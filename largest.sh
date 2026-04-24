echo enter first no
read a
echo enter first no
read b
echo enter first no
read c
if [ $a -gt $b ] && [ $a -gt $c ]
then
echo $a is greater
elif [ $b -gt $c ]
then
echo $b is greater
else
echo $c is greater
fi