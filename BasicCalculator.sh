# Basic Calculator

echo -n "Enter first number: "
read a
echo -n "Enter second number: "
read b

echo "Select operation (+ - * /): "
read op

case $op in
    +) result=$((a + b));;
    -) result=$((a - b));;
    \*) result=$((a * b));;
    /) result=$((a / b));;
    *) echo "Invalid operation"; exit;;
esac

echo "Result: $result"