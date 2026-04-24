#!/bin/bash

db="student_db.txt"

while true
do
echo "------ Student Database ------"
echo "1. View Records"
echo "2. Add Record"
echo "3. Delete Record"
echo "4. Exit"
echo "Enter your choice:"
read ch

case $ch in

1) echo "Student Records:"
   cat $db
   ;;

2) echo "Enter Student ID:"
   read id
   echo "Enter Student Name:"
   read name
   echo "Enter Course:"
   read course
   echo "$id | $name | $course" >> $db
   echo "Record Added."
   ;;

3) echo "Enter Student ID to delete:"
   read id
   grep -v "^$id" $db > temp.txt
   mv temp.txt $db
   echo "Record Deleted."
   ;;

4) echo "Exiting..."
   break
   ;;

*) echo "Invalid Choice"
   ;;

esac
done