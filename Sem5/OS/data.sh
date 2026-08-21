#!/bin/bash

echo "First 3 lines of the file:"

head -n 3 data

echo -e "\nls -l -t | tail - 1:"

ls -l -t | tail -1

echo -e "\nExplanation: It lists files by modification time (ls -l -t) and then (tail -1) shows the oldest file's details."

echo -e "\nFirst 100 characters of the file:"

head -c 100 data

echo -e "\nLast 3 lines of the file:"

tail -n 3 data

echo -e "\nLine 5 and Onwards:"

tail -n +5 data

echo -e "\nFirst 5 lines & storing it in the file 'shortlist'"

head -n 5 data > shortlist

echo -e "\nDisplay only name and city of teachers from 'shortlist'"

cut -d '|' -f2,4 shortlist

echo -e "\nCut  the 3rd field from 'shortlist' and save that in 'cutlist1'"

cut -d '|' -f3 shortlist > cutlist1
cat cutlist1

echo -e "\n Cut the 1st, 2nd & 4th field from 'shortlist' save that in 'cutlist2'"

cut -d '|' -f1,2,4 shortlist > cutlist2
cat cutlist2

echo -e "\nPaste the lines of 'cutlist1' & 'cutlist2' laterally"

paste cutlist1 cutlist2

echo -e "\nSort the file according to the name of teachers"

sort -t '|' -k2 data

echo -e "\nCut the teachers filed and store that in file 'teachers'"

cut -d '|' -f2 data > teachers
cat teachers

echo -e "\nSort the teachers according to name"

sort teachers

echo -e "\nSort the teachers in reverse"

sort -r teachers

cat > numfile <<EOF
2
6
10
27
4
EOF

echo -e "\nnumfile:"
cat numfile

echo -e "\nSorted 'numfile'"
sort numfile

echo -e "\nSorting is not possible bcz the numbers are treated as strings and are sorted based on the 1st character"

echo -e "\nCorrect command: sort -n numfile'"
sort -n numfile

echo -e "\nReplace '|' with 'n' and change lowercase to uppercase"
cat data | tr '|' 'n' | tr 'a-z' 'A-Z'

echo -e "\nNumber of appearance of the word 'Howrah':"
grep -o "Howrah" data | wc -l

echo -e "Line number in which 'Jadavpur' appears:"
grep -n "Jadavpur" data
