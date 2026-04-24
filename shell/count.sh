#!/bin/bash

echo "Enter directory name or path:"
read dir

if [ -d "$dir" ]; then
    count=$(ls -p "$dir" | grep -v / | wc -l)
    echo "Number of files: $count"
    echo "Not a directory"
fi
