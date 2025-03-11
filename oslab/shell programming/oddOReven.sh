#odd or even
echo enter number
read n
num=$(expr $n % 2)
if [ $num -eq 0 ]
then 
echo even
else 
echo odd
fi