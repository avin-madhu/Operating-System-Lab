# Program to find factorial of a number

echo -n "Enter number: "
read num

fact=1

while [ $num -ne 0 ]
do
        fact=$(( $fact * $num ))
        num=$(( $num - 1 ))
done

echo "Factorial is $fact"