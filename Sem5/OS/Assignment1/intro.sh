echo "Create 5 empty files"
touch empty1 empty2 empty3 empty4 empty5

echo -e "\nCreate a file 'text' and store name, age & address"
echo -e "\nEnter name:"
read nm
echo -e "\nEnter age:"
read age
echo -e "\nEnter address:"
read addr

echo -e "\n$nm\n$age\n$addr\n" > text

echo -e "\nDisplay text file"
cat text

cp text newtext

echo -e "\nDisplay newtext file"
cat newtext

echo -e "\nCreate file 'matter' and type 2 sentences"
cat > matter <<EOF
andaaz-e-bayaan ka paisa hai
kuchh itna bhi khaas nahi likhta hoon
EOF

echo -e "\nFile matter:"
cat matter

echo -e "\nCombine 'text' & 'matter' into 'txtmat'"
cat text matter > txtmat

echo -e "\nDisplay txtmat:"
cat txtmat

echo -e "\nDelete text file"
rm text

echo -e "\nChange permission of file newtext to 666"
chmod 666 newtext

echo -e "\nRename file nnewtext to oldtext"
mv newtext oldtext

echo -e "\nCreate a directory mydir"
mkdir mydir

echo -e "\nMove the files oldtext and matter to the directory mydir"
mv oldtext matter mydir

echo -e "\nCreate another directory newdir"
mkdir newdir

echo -e "\nCopy contents of mydir to newdir"
cp -r mydir/* newdir/

echo -e "\nDisplay date in dd/mm/yy format"
date +"%d/%m/%Y"

echo -e "\ncheck the current users"
who

echo -e "\nObtain a complete listing of all files and directories in the whole system"
ls -laR

echo -e "Count the number of users currently logged into the system"
who | wc -l





