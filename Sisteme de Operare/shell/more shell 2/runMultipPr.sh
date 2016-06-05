#!/bin/bash
count=0;
while [ $count -lt 3 ]
do
	read x
	($x);
	if [ $? != 0 ]
	then
		count=`expr $count + 1`;
	fi
done
exit 0
