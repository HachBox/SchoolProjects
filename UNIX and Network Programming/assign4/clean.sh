#!/bin/bash

directory=`pwd`
askDelete() 
{
	echo "$1 was found. Do you want to delete it? (y/n) "
	read anw
	if [ $anw == "y" ];then 
		rm $1
		echo "$1 has been removed"
	else
		"$1 file has not been removed."
	fi
}

clear
directory=`pwd`
choice=true
echo -e "Welcome to the CLEANER program! \n"
while [ $choice == true ];do
	echo -e " Enter 1 to delete by filename \n Enter 2 to delete by a string within the file \n Enter 3 or quit this program\n "
	read num
	if [ $num -ge "3" ] ; then 
		exit
	fi

	case $num in 
		"file") read -p "Enter in the name of the file to delete: " file

			count=0
			filename=$(find $directory -type f -name "$file")
		for filefound in $filename; do
			askDelete $filefound 
			count=$((count$count+1))
		done

		if [ $count == 0 ]; then
			echo "No files found"
		fi ;;

	"string") read -p "Enter the string to delete file that contains it: " string
		count=o

	filename=$
for filefound in $filename; do
	grep -q "$string" "$filefound" 
	if [ $? == 0 ] ; then
		askDelte $filefound
		count=$(($count+1))
	fi
done

if [ $count == 0 ] ; then
	echo "No string found."
fi ;;
esac
done

