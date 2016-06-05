# Write a shell script that creates a file containing the name of each 
# text files from a folder (given as parameter) and it's subfolders 
# that contain words longer than n characters (read n  from keyboard).  
#" The file will be ordered alphabetically.
#!/bin/bash
if [ -d $1 ]
then
	echo read n: 
	read n
	for fis in `find  $1`
	do
	if [ -f $fis ]
	then 
	
		for word in `cat $fis`
		do	
			nr=`echo -n  $word | wc -c`
			if [ $nr -gt $n ]; then
			echo $fis
			break
			fi
		done
	fi
	done 
	
else
	echo $1 is not a directory
	exit 1
fi

