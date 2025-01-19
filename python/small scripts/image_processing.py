from PIL import Image
import os

filename = "test.png"
image_extensions = ["jpg", "png", "jpeg"]

# remove metadata from a single image file
# save either as new file or replace original file
def remove_metadata(filename, replace=False):
    # skip if not a valid image
    if filename.split(".")[-1] not in image_extensions:
        return False
    
    # otherwise open image
    image = Image.open(filename)
    
    # new name if replace is false
    if not replace:
        # output filename -> original name _cleaned
        ext = image.filename.split('.')[-1]
        filename = image.filename.split(f".{ext}")[0] + "_cleaned." + ext    
        
    try:
        image.convert("RGB").save(filename)
        print(f"Removed metadata: {image.filename} -> {filename}")
        return True
    
    except Exception as e:
        print(f"Error: {e} -> {image.filename}")
        return False
    

# loop through all files in a directory at all levels
# by default current directory i.e directory from where script is executed
def all_files(directory="./", replace=False):
    # walk through all subdirectories
    try:
        for root, dirs, files in os.walk(directory):
            for file in files:
                # remove metadata from file
                file = os.path.join(root, file).replace("\\", "/")
                remove_metadata(file, replace)
    except Exception as e:
        print(f"Error: {e} -> {directory}")


if __name__ == "__main__":
    # remove metadata from a single file
    remove_metadata("test.jpg", replace=True)

    # all files in current directory
    all_files(replace=True)

    # all files in New Folder
    all_files(directory="New Folder/" ,replace=True)
