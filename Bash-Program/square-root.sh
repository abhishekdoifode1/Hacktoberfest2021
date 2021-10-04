read -p "Enter a number: " number
square_root=`echo "scale=4; sqrt($number)" | bc`
echo "Square Root of $number is $square_root"