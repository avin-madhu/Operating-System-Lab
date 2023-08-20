# Program to find the largest of N numbers

echo -n "Enter N numbers: "
read nums[10]

largest=0

for num in $nums
do
        if [ $num -gt $largest ]
        then
                largest=$num
        fi
done

echo "Largest number is $largest" 