#!/usr/bin/bash

search_dir='./'
for entry in "$search_dir"* #not fully sure whats happening here, need to look into it more
do
  cp $entry $entry.copy
done

#ASSIGNMENT
#Write ashell script that makes a copy of every file in the current
#working directory with the same name and an extension .copy. 
#For example, the file named myfile would have a copy named myfile.copy.

#SOURCE: https://stackoverflow.com/questions/2437452/how-to-get-the-list-of-files-in-a-directory-in-a-shell-script
