#!/bin/bash

echo "Enter name:"
read name

if [ -d "$name" ]; then
    echo "It is a directory"
else
    echo "It is not a directory"
fi
