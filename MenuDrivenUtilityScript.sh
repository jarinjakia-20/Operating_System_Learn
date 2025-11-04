# Menu Script Example

while true; do
    echo "Choose an option:"
    echo "1. Hello Script"
    echo "2. Calculator"
    echo "3. Even/Odd Check"
    echo "4. Exit"
    read choice

    case $choice in
        1) echo "Hello, Shell Script!" ;;
        2) bash /mnt/d/Operating System/BasicCalculator.sh ;;   # Run your calculator script
        3) bash EvenOrOdd.sh ;;      # Run your even-odd script
        4) echo "Goodbye!"; exit ;;
        *) echo "Invalid choice." ;;
    esac
done