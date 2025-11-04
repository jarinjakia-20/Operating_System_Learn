# Recursive File Lister

echo -n "Enter directory: "
read dir

if [ -d "$dir" ]; then
    echo "Listing all files under $dir:"
    find "$dir" -type f
else
    echo "Directory not found!"
fi