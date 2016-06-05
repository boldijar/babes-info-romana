#!/bin/sh
# 101_a
# Write a shell script that creates a file containing the name of each 
# text files from a folder (given as parameter) and it's subfolders 
# that contain words longer than n characters (read n  from keyboard).  
# The file will be ordered alphabetically.

read -p "n = " n
for x in `find $1 -type f`; do
    for i in `cat $x`; do
	if [ ${#i} -gt $n ]; then
	    file=`echo $x | awk -F "/" '{ print $NF }'`
	    echo $file
	    break
	fi
    done
done |sort -u > 101_a_out.txt