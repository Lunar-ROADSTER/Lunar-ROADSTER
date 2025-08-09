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

def get_ground_plane(points):
    pcd = o3d.geometry.PointCloud()
    pcd.points = o3d.utility.Vector3dVector(points)
    plane_model, inliers = pcd.segment_plane(distance_threshold=0.01,
                                             ransac_n=10,
                                             num_iterations=1000)
    return plane_model, inliers

def main(input_path, output_path):
    # Load the PCD file
    pcd = o3d.io.read_point_cloud(input_path)
    points = np.asarray(pcd.points)

    if points.size == 0:
        print("Point cloud is empty!")
        return

    # Step 1: Translate so bottom-left-most point becomes the new origin
    # origin = find_bottom_left_point(points)
    # print(f"Bottom-left-most point (new origin): {origin}")
    # points -= origin

    # Step 2: Rotate around Z-axis
    theta = 0 / 15
    rotation_matrix = np.array([
        [np.cos(theta), -np.sin(theta), 0],
        [np.sin(theta),  np.cos(theta), 0],
        [0,              0,             1]
    ])
    rotated_points = points @ rotation_matrix.T

    # Step 3: Filter points within a certain z range
    z_mask = np.logical_and(rotated_points[:, 2] > -0.25, rotated_points[:, 2] < 0.25)
    filtered_points = rotated_points[z_mask]
    print(f"Original points: {len(points)} -> Filtered points: {len(filtered_points)}")

    plane_model, inliers = get_ground_plane(filtered_points)
    a, b, c, d = plane_model
    print(f"Ground plane model: {a:.3f}x + {b:.3f}y + {c:.3f}z + {d:.3f} = 0")

    # Step 4: Compute signed distance to ground plane
    normal = np.array([a, b, c])
    norm = np.linalg.norm(normal)
    signed_distances = (filtered_points @ normal + d) / norm

    # Step 5: Replace Z with ground-relative height
    ground_aligned_points = filtered_points.copy()
    ground_aligned_points[:, 2] = signed_distances

    # Clamp near-ground noise
    clamp_mask = np.logical_and(
        ground_aligned_points[:, 2] > -0.001,
        ground_aligned_points[:, 2] <  0.001
    )
    ground_aligned_points[clamp_mask, 2] = 0.0
    print(f"Clamped {np.sum(clamp_mask)} points to Z = 0")

    # Step 6: Save output
    pcd.points = o3d.utility.Vector3dVector(ground_aligned_points)
    o3d.io.write_point_cloud(output_path, pcd)
    print(f"Ground-aligned point cloud saved to: {output_path}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 transform_map.py original_map.pcd map.pcd")
        sys.exit(1)

    input_pcd = sys.argv[1]
    output_pcd = sys.argv[2]
    main(input_pcd, output_pcd)