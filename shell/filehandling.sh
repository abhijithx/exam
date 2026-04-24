#!/bin/bash

# (i) Input a page profile to yourself and copy it into another existing file

echo "Enter your profile (Press CTRL+D when finished):"
cat > profile.txt          # Create and input profile

echo "Copying profile into existing file 'backup.txt'"
cat profile.txt >> backup.txt


# (ii) Start printing file at a certain line

echo "Enter the line number from where printing should start:"
read line

echo "Printing file from line $line:"
tail -n +$line profile.txt


# (iii) Print all the differences between two files and copy the files

echo "Enter first file name:"
read file1
echo "Enter second file name:"
read file2

echo "Differences between $file1 and $file2:"
diff $file1 $file2

echo "Copying files..."
cp $file1 copy_$file1
cp $file2 copy_$file2


# (iv) Print lines matching a certain word pattern

echo "Enter a word/pattern to search:"
read pattern

echo "Lines matching '$pattern' in profile.txt:"
grep "$pattern" profile.txt