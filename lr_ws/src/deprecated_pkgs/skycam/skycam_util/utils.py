def load_files_list(files_txt):
    with open(files_txt, "r") as f:
        names = [ln.strip() for ln in f.readlines() if ln.strip()]
    return names


def load_labels_xyz(labels_txt):
    labels = []
    with open(labels_txt, "r") as f:
        for ln in f:
            ln = ln.strip()
            if not ln:
                continue
            parts = ln.split()
            if len(parts) < 3:
                continue
            x, y, z = map(float, parts[:3])
            labels.append((x, y, z))
    return labels


def load_labels_xyzrpy(labels_txt):
    labels = []
    with open(labels_txt, "r") as f:
        for ln in f:
            ln = ln.strip()
            if not ln:
                continue
            parts = ln.split()
            if len(parts) < 8:
                continue
            x, y, z, _, _, roll, pitch, yaw = parts[:8]
            labels.append((
                float(x),
                float(y),
                float(z),
                float(roll),
                float(pitch),
                float(yaw),
            ))
    return labels