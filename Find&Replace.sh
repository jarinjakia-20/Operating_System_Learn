# Find and Replace Text

echo -n "Enter filename: "
read file
echo -n "Enter word to find: "
read find
echo -n "Enter word to replace: "
read replace

if [ -f "$file" ]; then
    sed -i "s/$find/$replace/g" "$file"
    echo "All occurrences of '$find' replaced with '$replace'."
else
    echo "File not found!"
fi