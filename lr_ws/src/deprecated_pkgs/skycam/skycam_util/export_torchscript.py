#! python3

import torch
import torch.nn as nn
import argparse
    
class SkyCamConvNet(nn.Module):
    def __init__(self,
                 in_channels=3,
    ):
    
        super().__init__()

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

    def forward(self, x):
        return self.head(self.features(x))

def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--ckpt", type=str, default="skycam_convnet.pt")
    parser.add_argument("--out", type=str, default="skycam_convnet_ts.pt")
    parser.add_argument("--channels", type=int, default=None)
    parser.add_argument("--image_size", type=int, default=None)
    return parser.parse_args()

def main():
    args = parse_args()
    ckpt = torch.load(args.ckpt, map_location="cpu")
    channels = args.channels if args.channels is not None else ckpt.get("channels", 3)
    image_size = args.image_size if args.image_size is not None else ckpt.get("image_size", 224)

    model = SkyCamConvNet(in_channels=channels)
    model.load_state_dict(ckpt["model_state_dict"])
    model.eval()

    ex = torch.zeros(1, channels, image_size, image_size)
    ts = torch.jit.trace(model, ex)
    ts.save(args.out)
    print(f"Saved TorchScript module to: {args.out} (C,H,W)=({channels},{image_size},{image_size})")

if __name__ == "__main__":
    main()