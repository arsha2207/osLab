#basic arithmetic operations
echo enter two numbers
read a b
sum=$(expr $a + $b)
dif=$(expr $a - $b)
pro=$(expr $a \* $b)
div=$(expr $a / $b)
echo sum is $sum
echo difference is $dif
echo product is $pro
echo quotient is $div