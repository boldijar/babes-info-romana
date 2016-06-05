#!/bin/sh
# 101_b
# Write a shell script that will create a file that contains a list of all
# the files from a folder given in the command line and it's subfolders,
# that have none of the read, write and execute permission for the group.
# Then, for each file, grant read permission to the group. 

for x in `find $1 -type f`; do
    per=`ls -l $x | awk '{ print $1 }'`
    if [ `echo $per | grep "\-...---..."` ]; then
	echo $x
	`chmod 640 $x`
    fi
done | sort -u > 101_b_out.txt