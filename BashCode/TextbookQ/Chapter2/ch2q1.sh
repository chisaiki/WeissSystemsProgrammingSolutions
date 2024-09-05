#!/usr/bin/bash

if [ $# -eq 0 ]
then
	seq 100 | shuf >| permutation100
else
	echo Too Many Arguments
fi

#ASSIGNMENT
#Look at the man page for the shuf command, and then write a command 
#that generates a random permutation of the integers 
#from 1 to 100 in a file named permutation100 in your current working directory.
