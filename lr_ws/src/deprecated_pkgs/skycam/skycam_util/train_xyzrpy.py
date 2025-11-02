#! python3

import argparse
import os
import matplotlib.pyplot as plt
import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
from PIL import Image
from utils import load_files_list, load_labels_xyzrpy


class SkyCamDataset(torch.utils.data.Dataset):
    def __init__(self, images_dir, files_txt, labels_txt, image_size=224, channels=3):
        super().__init__()
        self.images_dir = images_dir
        self.files = load_files_list(files_txt)
        self.labels = load_labels_xyzrpy(labels_txt)
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
        x, y, z, roll, pitch, yaw = self.labels[idx]

        img_t = self._load_image_tensor(img_path)
        target = torch.tensor([x, y, z, roll, pitch, yaw], dtype=torch.float32)
        return img_t, target, name


class SkyCamConvNet(nn.Module):
    def __init__(
        self,
        in_channels,
        lr=1e-3,
        device="cpu",
    ):
        
        super().__init__()
        self.device = device
        
        self.features = nn.Sequential(
            nn.Conv2d(in_channels, 16, 3, padding=1),  # -> 16xHxW
            nn.ReLU(inplace=True),
            nn.MaxPool2d(2),                           # /2

            nn.Conv2d(16, 32, 3, padding=1),           # -> 32x(H/2)x(W/2)
            nn.ReLU(inplace=True),
            nn.MaxPool2d(2),                           # /4

            nn.AdaptiveAvgPool2d((1, 1)),              # -> 32x1x1
        )

        self.head = nn.Sequential(
            nn.Flatten(),                              # 32
            nn.Linear(32, 16),
            nn.ReLU(inplace=True),
            nn.Linear(16, 6),                          # x, y, z, roll, pitch, yaw
        )
        
        self.to(self.device)
        self.criterion = nn.MSELoss()
        self.optimizer = optim.Adam(self.parameters(), lr=lr)

    def forward(self, x):
        return self.head(self.features(x))

    def train_step(self, batch):
        self.train()
        imgs, targets, _ = batch
        imgs = imgs.to(self.device, non_blocking=True)
        targets = targets.to(self.device, non_blocking=True)

        preds = self.forward(imgs)
        loss = self.criterion(preds, targets)

        self.optimizer.zero_grad()
        loss.backward()
        nn.utils.clip_grad_norm_(self.parameters(), max_norm=1.0)
        self.optimizer.step()

        return float(loss.detach().cpu().item())


def parse_args():
    parser = argparse.ArgumentParser(description="Train a ConvNet on SkyCam regression.")
    parser.add_argument("--data_dir", type=str, default='./data',
                   help="Directory with images.")
    parser.add_argument("--files_txt", type=str, default="train_files.txt",
                   help="List of image filenames to load (default: train_files.txt).")
    parser.add_argument("--labels_txt", type=str, default="train_labels.txt",
                   help="Labels (x y z img_ns pose_ns roll pitch yaw) file (default: train_labels.txt).")
    parser.add_argument("--image_size", type=int, default=224,
                   help="Square resize dimension before feeding to the CNN.")
    parser.add_argument("--channels", type=int, default=3, choices=[1, 3],
                   help="1 for grayscale, 3 for RGB.")
    parser.add_argument("--batch_size", type=int, default=16)
    parser.add_argument("--epochs", type=int, default=50)
    parser.add_argument("--lr", type=float, default=1e-3)
    parser.add_argument("--num_workers", type=int, default=4)
    parser.add_argument("--save_path", type=str, default="skycam_convnet.pt",
                   help="Output checkpoint path.")
    return parser.parse_args()


def main():
    args = parse_args()
    device = "cuda" if torch.cuda.is_available() else "cpu"
    print(f"Using device: {device}")

    files_txt_path = os.path.join(args.data_dir, args.files_txt)
    labels_txt_path = os.path.join(args.data_dir, args.labels_txt)
    if not os.path.exists(files_txt_path):
        raise FileNotFoundError(f"Missing files list: {files_txt_path}")
    if not os.path.exists(labels_txt_path):
        raise FileNotFoundError(f"Missing labels file: {labels_txt_path}")

    dataset = SkyCamDataset(
        images_dir=args.data_dir,
        files_txt=files_txt_path,
        labels_txt=labels_txt_path,
        image_size=args.image_size,
        channels=args.channels,
    )

    loader = torch.utils.data.DataLoader(
        dataset,
        batch_size=args.batch_size,
        shuffle=True,
        num_workers=(0 if os.name == "nt" else args.num_workers),
        pin_memory=(device == "cuda"),
        drop_last=False,
    )

    model = SkyCamConvNet(in_channels=args.channels, lr=args.lr, device=device)
    
    # Training loop
    losses = []
    for epoch in range(1, args.epochs + 1):
        epoch_loss = 0.0
        for batch in loader:
            loss_val = model.train_step(batch)
            epoch_loss += loss_val
        epoch_loss /= max(1, len(loader))
        losses.append(epoch_loss)
        print(f"[Epoch {epoch:03d}] loss={epoch_loss:.6f}")

    # Save checkpoint
    torch.save(
        {
            "model_state_dict": model.state_dict(),
            "arch": "SkyCamConvNet",
            "channels": args.channels,
            "image_size": args.image_size,
            "mean_train_loss": float(np.mean(losses)) if losses else None,
        },
        args.save_path,
    )
    print(f"Saved model to: {args.save_path}")
    
    plt.figure()
    plt.plot(np.arange(1, len(losses) + 1), losses)
    plt.xlabel("Epoch")
    plt.ylabel("MSE Loss (x,y,z,roll,pitch,yaw)")
    plt.title("SkyCam ConvNet Training Loss")
    plt.grid(True, alpha=0.3)
    plt.tight_layout()
    plt.savefig("training_loss.png")
    plt.close()

if "__main__" == __name__:
    main()
