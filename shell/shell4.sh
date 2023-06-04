# Program to check whether a number is odd or even

echo -n "Enter a number: "
read num

remainder=`expr $num % 2`

if [ $remainder -eq 0 ]
then
        echo "$num is even"
else
        echo "$num is odd"
fi