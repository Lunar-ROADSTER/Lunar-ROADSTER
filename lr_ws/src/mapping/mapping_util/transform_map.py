# To use this helper function, enter the following command in the command line:
# python3 transform_map.py original_map.pcd map.pcd

import open3d as o3d
import numpy as np
import sys

def find_bottom_left_point(points):
    # Lowest X (left), then lowest Y (bottom)
    min_x = np.min(points[:, 0])
    candidates = points[points[:, 0] == min_x]
    bottom_left_point = candidates[np.argmin(candidates[:, 1])]  # min Y among min X
    return bottom_left_point

def main(input_path, output_path):
    # Load the PCD file
    pcd = o3d.io.read_point_cloud(input_path)
    points = np.asarray(pcd.points)

    if points.size == 0:
        print("Point cloud is empty!")
        return

    # Step 1: Translate so bottom-left-most point becomes the new origin
    origin = find_bottom_left_point(points)
    print(f"Bottom-left-most point (new origin): {origin}")
    points -= origin

    # Step 2: Rotate around Z-axis
    theta = np.pi / 15
    rotation_matrix = np.array([
        [np.cos(theta), -np.sin(theta), 0],
        [np.sin(theta),  np.cos(theta), 0],
        [0,              0,             1]
    ])
    rotated_points = points @ rotation_matrix.T

    # Step 3: Filter points within a certain z range
    z_mask = np.logical_and(rotated_points[:, 2] > -0.5, rotated_points[:, 2] < 0.5)
    filtered_points = rotated_points[z_mask]

    print(f"Original points: {len(points)} -> Filtered points: {len(filtered_points)}")

    # Step 4: Save result
    pcd.points = o3d.utility.Vector3dVector(filtered_points)
    o3d.io.write_point_cloud(output_path, pcd)
    print(f"Transformed, rotated, and filtered point cloud saved to: {output_path}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 transform_map.py original_map.pcd map.pcd")
        sys.exit(1)

    input_pcd = sys.argv[1]
    output_pcd = sys.argv[2]
    main(input_pcd, output_pcd)
