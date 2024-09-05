#!/usr/bin/bash

filepath='./shopping_list'

if [  -f $filepath ] #checks to see if a file exists by checking its path to see if it exists through this path
then
	cat > shopping_list
else
	echo shopping_list file doesnt exist, refer to chapter 2 problem 4 to make it
fi

#ASSIGNMENT
#Using nothing but the cat command and redirection, 
#show how to add the lines:
#milk
#bread
#eggs
#flour
#sugar

#NOTE:  ‘-f’ test operator only checks for regular files
#SOURCE: https://ioflood.com/blog/bash-if-file-exists/#:~:text=In%20bash%2C%20you%20can%20check,and%20is%20a%20regular%20file.
