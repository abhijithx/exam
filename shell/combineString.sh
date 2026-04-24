#!/bin/bash

read -p "How many strings do you want to enter? " n

combined=""

for ((i=1; i<=n; i++))
do
    read -p "Enter string $i: " str
    combined+="$str "
done

echo "Combined string: $combined"