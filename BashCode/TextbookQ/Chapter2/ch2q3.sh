#!/usr/bin/bash

if [ $1 -ge 0 ]
then
	for i in {1..5}
	do
		ps
		sleep $1
	done
else
	echo Invalid number of arguments
	echo Usage: command '<number of seconds to sleep>'
fi


#ASSIGNMENT
#Modify the preceding script so that it accepts as a command line
#argument the number of seconds between runs of the ps command.
