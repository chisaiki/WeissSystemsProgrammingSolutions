#!/bin/bash
 # This script demonstrates the use of positional parameters and how to access/interact with them.
 
 echo "The command that you typed is $0."
 
 if [ $# -gt 0 ]  
 then
 	echo -n "The first word after the command is '$1' "
 	echo "and number of words is $#"
 	echo "The entire set of words is:"
 	echo "'$*'"
 else
 	echo You did not enter anything after $0.
	echo usage: script2 [list of words]
 fi
