import os

for f in os.listdir():
    os.rename(f, f"sort_{f.split('_')[0]}.py")