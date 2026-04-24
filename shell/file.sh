echo "1001 RAM 97" >> myfile
echo "1002 NEHA 89" >> myfile
echo "1010 DIVYA 77" >> myfile
echo "1025 RAHUL 65" >> myfile
echo "1012 ARUN 99" >> myfile
echo "1013 NISHA 76" >> myfile
echo "First 2 rows:"
head -2 myfile
echo "Last 2 rows:"
tail -2 myfile
cp myfile mycopyfile
echo "Number of lines: $(wc -l < myfile)"
echo "Number of words: $(wc -w < myfile)"
echo "Number of characters: $(wc -c < myfile)"
echo "3rd Row:"
sed -n '3p' myfile
cat myfile >> myappendfile

