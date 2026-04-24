#!/bin/bash

# (i) Showing the count of users logged in
echo "Number of users currently logged in:"
who | wc -l


# (ii) Printing column list of files in home directory
echo "Files in home directory (column format):"
ls ~


# (iii) Listing jobs with below normal priority
echo "Processes with below normal priority:"
ps -eo pid,ni,cmd | awk '$2 > 0'