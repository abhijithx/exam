#!/bin/bash

echo "Enter file name:"
read file

if [ -f "$file" ]; then
    tac "$file"
else
    echo "File not found"
fi
