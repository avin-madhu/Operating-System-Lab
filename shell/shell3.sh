// shell program to swap to values

echo -n "Enter the value of A: "
read a
echo -n "Enter the value of B: "
read b
t= $a a= $b b= $t
echo "values after swapping"
echo "A value is $a"
echo "B value is $b"