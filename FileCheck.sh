# Check if file exists

echo -n "Enter filename: "
read filename

if [ -f "$filename" ]; then
    echo "$filename exists and is a regular file."
elif [ -d "$filename" ]; then
    echo "$filename is a directory."
else
    echo "$filename does not exist."
fi