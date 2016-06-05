# 71. a)
# Write a shell script that takes pairs of parameters (a filename and a number
# n) and outputs for each pair the name of the file, the number n and the nth
# word from each file.

#!/bin/bash

n=$1
fis=$2

if [ -f $fis ]
then
	cat $fis | tr -t "\n" " " | tr -t . " " | awk -v nn=$n '{ print $nn }'
else
	echo Nu ati dat un fisier
fi
exit 0

