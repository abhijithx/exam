
read -p "Enter a string: " str
read -p "Enter starting position: " start
read -p "Enter length: " len

substr=${str:start:len}

echo "Substring: $substr"