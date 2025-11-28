mkdir -p jolly jolly_2

touch jolly/andrea.txt jolly/giuseppe.doc jolly/giovanni.txt jolly/Alessandro.txt
echo "Ciao" > jolly/andrea.txt
echo "Come stai?" > jolly/giuseppe.doc
echo "Buongiorno" > jolly/giovanni.txt
echo "Benvenuto" > jolly/Alessandro.txt

ls jolly/*.txt | grep -E '^.{2}e'

find jolly -maxdepth 1 -name "*.txt" -size -6c -exec cp {} jolly_2/ \;

rm jolly/*.doc

cat jolly/*.txt > jolly/risultati.txt

cat jolly/risultati.txt
