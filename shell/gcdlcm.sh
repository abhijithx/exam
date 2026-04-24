#!/bin/bash

echo "Enter first number:"
read a
echo "Enter second number:"
read b

x=$a
y=$b

# Compute GCD using Euclid's algorithm
while [ $y -ne 0 ]
do
    temp=$y
    y=$((x % y))
    x=$temp
done

gcd=$x

# Compute LCM
lcm=$(( (a * b) / gcd ))

echo "GCD of $a and $b is: $gcd"
echo "LCM of $a and $b is: $lcm"