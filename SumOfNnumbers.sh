# Sum of N Numbers

echo -n "Enter numbers separated by space: "
read -a nums

sum=0
for n in "${nums[@]}"
do
    sum=$((sum + n))
done

echo "Sum = $sum"