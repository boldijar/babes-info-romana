#!/bin/bash
#13 a)Write a shell script that will show on the screen every s seconds, a top
#of the
#first n users on the linux system, sorted by the number their running
#processes (n will be read from keyboard and s from command line).
echo Read n:
read n
while [ 0 ];
do
	ps -ef > tempfile0
		
	awk '{print $1}' tempfile0 | sort | uniq -c | sort -rbn > tempfile

	grep -m$n . tempfile | awk '{   print $1" "$2 }'
	rm tempfile
	rm tempfile0
	sleep $1
	echo 
	
done

