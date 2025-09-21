def load_files_list(files_txt):
    with open(files_txt, "r") as f:
        names = [ln.strip() for ln in f.readlines() if ln.strip()]
    return names

def load_labels(labels_txt):
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