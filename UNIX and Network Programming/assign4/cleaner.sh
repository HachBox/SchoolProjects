#!/bin/bash
clear
#code a subroutine at top called askDelete

askDelete(){	#function called from the main logic below
	read -p "$ans was FOUND. Still want to delete it? (y/n)" anw
	if  [ "$anw" == Y ] || [ "$anw" == y ] ; then
		echo "$ans has been removed"	#($1 is the file)
	elif [ "$anw" == n ] || [ "$anw" == N] ; then
		echo "$ans has not been removed"
	fi
}

#Welcome message
echo "Welcome to the CLEANER program!"
echo directory = `pwd`      #set variable directory to be value of your current dir

#Display menu choices
echo Enter 1 to delete by filename.
echo Enter 2 to delete by a string within the file.
echo Enter 3 or quit to exit this program

read num

while [ "$num" != 3 ] ;
#set -x
do
	if [ "$num" = 1 ] || [ "$num" = file ] ;
	then
		read -p "Enter in the name of the file to delete: " ans

		find `pwd` -name "$ans"

		if [ $ans -lt 0 ] ; 
		then 
			echo "file was not found"
		else
			askDelete
		fi
	fi

	if [ "$num" == 2 ] || [ "$num" = string ] ;
	then
		read -p "Enter the string to delete files that contain: " ans

		find `pwd` -name "$ans"

		if [ $ans -lt $ans ] ;
		then
			echo "string was not found"
		else
			askDelete
		fi
	fi
done

exit 0
