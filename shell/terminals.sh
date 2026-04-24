#!/bin/bash

echo "Logged-in users and terminals:"
who

count=$(who | wc -l)
echo "Number of terminals logged in: $count"
