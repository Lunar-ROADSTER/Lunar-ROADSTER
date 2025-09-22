#! python3

import argparse
import os
import csv
import numpy as np
import torch
import torch.nn as nn
from PIL import Image
from utils import load_files_list, load_labels_xyz

class SkyCamDataset(torch.utils.data.Dataset):
    def __init__(self, images_dir, files_txt, labels_txt, image_size=224, channels=3):
        super().__init__()
        self.images_dir = images_dir
        self.files = load_files_list(files_txt)
        self.labels = load_labels_xyz(labels_txt)
        self.image_size = image_size
        self.channels = channels

        if len(self.files) != len(self.labels):
            raise ValueError(f"files/labels size mismatch: {len(self.files)} files vs {len(self.labels)} labels.")

    def __len__(self):
        return len(self.files)

    def _load_image_tensor(self, path):
        try:
            img = Image.open(path).convert("RGB")
        except Exception as e:
            raise RuntimeError(f"Failed to open image {path}: {e}")
        if self.channels == 1:
            img = img.convert("L")
        img = img.resize((self.image_size, self.image_size), Image.BILINEAR)
        arr = np.asarray(img, dtype=np.float32) / 255.0
        if self.channels == 1:
            arr = np.expand_dims(arr, axis=0) # HxW -> 1xHxW
        else:
            arr = np.transpose(arr, (2, 0, 1)) # HxWx3 -> 3xHxW
        return torch.from_numpy(arr)  # float32, [C,H,W]

    def __getitem__(self, idx):
        name = self.files[idx]
        img_path = os.path.join(self.images_dir, name)
        x, y, z = self.labels[idx]

        img_t = self._load_image_tensor(img_path)
        target = torch.tensor([x, y, z], dtype=torch.float32)
        return img_t, target, name
    
    
class SkyCamConvNet(nn.Module):
    def __init__(self,
                 in_channels,
                 device="cpu"
    ):
    
        super().__init__()
        self.device = device

        self.features = nn.Sequential(
            nn.Conv2d(in_channels, 16, 3, padding=1),
            nn.ReLU(inplace=True),
            nn.MaxPool2d(2),

            nn.Conv2d(16, 32, 3, padding=1),
            nn.ReLU(inplace=True),
            nn.MaxPool2d(2),

            nn.AdaptiveAvgPool2d((1, 1)),
        )

        self.head = nn.Sequential(
            nn.Flatten(),
            nn.Linear(32, 16),
            nn.ReLU(inplace=True),
            nn.Linear(16, 3),
        )

        self.to(self.device)

    def forward(self, x):
        return self.head(self.features(x))


def compute_metrics(preds, gts):
    diff = preds - gts
    mse = (diff ** 2).mean(axis=0)
    rmse = np.sqrt(mse)
    mae = np.abs(diff).mean(axis=0)
    return {
        "MSE_x": mse[0], "MSE_y": mse[1], "MSE_z": mse[2], "MSE_mean": mse.mean(),
        "RMSE_x": rmse[0], "RMSE_y": rmse[1], "RMSE_z": rmse[2], "RMSE_mean": rmse.mean(),
        "MAE_x": mae[0], "MAE_y": mae[1], "MAE_z": mae[2], "MAE_mean": mae.mean(),
    }
    

def parse_args():
    parser = argparse.ArgumentParser(description="Validate SkyCam model on eval set.")
    parser.add_argument("--ckpt_path", type=str, default="skycam_convnet.pt",
                   help="Path to trained checkpoint (.pt) saved by training.")
    parser.add_argument("--data_dir", type=str, default="./eval",
                   help="Eval directory containing images and eval text files.")
    parser.add_argument("--files_txt", type=str, default="eval_files.txt",
                   help="Eval file list (default: eval_files.txt).")
    parser.add_argument("--labels_txt", type=str, default="eval_labels.txt",
                   help="Eval labels file (default: eval_labels.txt).")
    parser.add_argument("--image_size", type=int, default=None,
                   help="Override image size (otherwise use size saved in checkpoint).")
    parser.add_argument("--channels", type=int, default=None, choices=[1, 3],
                   help="Override channels (otherwise use channels saved in checkpoint).")
    parser.add_argument("--batch_size", type=int, default=64)
    parser.add_argument("--num_workers", type=int, default=4)
    return parser.parse_args()


def main():
    args = parse_args()
    device = "cuda" if torch.cuda.is_available() else "cpu"
    print(f"Using device: {device}")

    # Load checkpoint
    ckpt = torch.load(args.ckpt_path, map_location=device)
    ckpt_channels = ckpt.get("channels", 3)
    ckpt_image_size = ckpt.get("image_size", 224)

    channels = args.channels if args.channels is not None else ckpt_channels
    image_size = args.image_size if args.image_size is not None else ckpt_image_size

    print(f"Loaded checkpoint: {args.ckpt_path}")
    print(f"Eval config: channels={channels}, image_size={image_size}")

    # Eval dataset/loader
    files_txt_path = os.path.join(args.data_dir, args.files_txt)
    labels_txt_path = os.path.join(args.data_dir, args.labels_txt)
    if not os.path.exists(files_txt_path):
        raise FileNotFoundError(f"Missing eval files list: {files_txt_path}")
    if not os.path.exists(labels_txt_path):
        raise FileNotFoundError(f"Missing eval labels file: {labels_txt_path}")

    eval_set = SkyCamDataset(
        images_dir=args.data_dir,
        files_txt=files_txt_path,
        labels_txt=labels_txt_path,
        image_size=image_size,
        channels=channels,
    )
    loader = torch.utils.data.DataLoader(
        eval_set,
        batch_size=args.batch_size,
        shuffle=False,
        num_workers=(0 if os.name == "nt" else args.num_workers),
        pin_memory=(device == "cuda"),
        drop_last=False,
    )

    # Load model
    model = SkyCamConvNet(in_channels=channels, device=device)
    model.load_state_dict(ckpt["model_state_dict"])
    model.eval()

    # Inference
    all_preds, all_gts, all_names = [], [], []
    with torch.no_grad():
        for imgs, targets, names in loader:
            imgs = imgs.to(device, non_blocking=True)
            preds = model(imgs).cpu().numpy()
            gts = targets.cpu().numpy()

            all_preds.append(preds)
            all_gts.append(gts)
            all_names.extend(list(names))

    if all_preds:
        all_preds = np.concatenate(all_preds, axis=0)
        all_gts = np.concatenate(all_gts, axis=0)
    else:
        all_preds = np.zeros((0, 3), dtype=np.float32)
        all_gts = np.zeros((0, 3), dtype=np.float32)

    # Metrics
    metrics = compute_metrics(all_preds, all_gts)
    print("\n=== Evaluation Metrics ===")
    for k in ["MSE_x","MSE_y","MSE_z","MSE_mean","RMSE_x","RMSE_y","RMSE_z","RMSE_mean","MAE_x","MAE_y","MAE_z","MAE_mean"]:
        print(f"{k}: {metrics[k]:.6f}")
        

if __name__ == "__main__":
    main()