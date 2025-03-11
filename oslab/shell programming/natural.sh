#display n natural numbers
echo enter limit
read n
i=1
echo The numbers are 
while [ $i -le $n ]
do 
echo $i
i=$(expr $i + 1)
done