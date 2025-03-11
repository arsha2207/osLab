#sum of 5 natural numbers
sum=0
for i in 1 2 3 4 5
do
sum=$(expr $sum + $i)
done
echo sum of first 5 natural numbers is $sum 
