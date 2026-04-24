echo enter first no
read a
echo enter second no
read b
echo third no
read c
if [ $a -ge $b ] && [ $a -ge $c ]; then
    echo greatest is $a
elif [ $b -ge $a ] && [ $b -ge $c ]; then
    echo greatest is $b 
else
  echo greatest is $c    
fi    