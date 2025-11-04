# Backup Script

echo -n "Enter file or directory to backup: "
read source

if [ ! -e "$source" ]; then
    echo "Source not found!"
    exit 1
fi

backup="backup_$(basename "$source")_$(date +%Y%m%d_%H%M%S).tar.gz"
tar -czf "$backup" "$source"
echo "Backup created: $backup"