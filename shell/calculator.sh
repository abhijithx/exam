#!/bin/bash

echo "Enter first number:"
read a

echo "Enter second number:"
read b

echo "Choose operation:"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
read choice

case $choice in
1)
    echo "Result: $((a + b))"
    ;;
2)
    echo "Result: $((a - b))"
    ;;
3)
    echo "Result: $((a * b))"
    ;;
4)
    if [ $b -eq 0 ]; then
        echo "Error: Division by zero"
    else
        echo "Result: $((a / b))"
    fi
    ;;
*)
    echo "Invalid choice"
    ;;
esac
