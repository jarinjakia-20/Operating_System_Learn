echo -n "Enter filename: "
read file

if [ -f "$file" ]; then
    words=$(wc -w < "$file")
    lines=$(wc -l < "$file")
    chars=$(wc -m < "$file")
    echo "Lines: $lines | Words: $words | Characters: $chars"
else
    echo "File not found!"
fi