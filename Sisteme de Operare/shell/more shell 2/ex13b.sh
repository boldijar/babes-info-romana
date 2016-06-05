#write a shell script that will create a file that contains a list of all
#the files
#from a folder given in the command line and it?s subfolders, that have none
#of the read, write and execute permission for the group.Then, for each file,
#grant read permission to the group
#!/bin/bash
if [ $# -gt 1 ]
then
	echo Please pass only one param
	exit 1
fi
if [ ! -d $1 ] 
then
	echo Not a directory
	exit 2
fi
a=`find $1`
for item in  $a
do
	b=`stat -c %a $item`
	if [[ $b =~ [0-9]0[0-9] ]] 
	then
	echo $item >> result.txt
	fi
done
echo The file result.txt is created
for item in `cat  result.txt`
do
	chmod g=r $item
done
echo Read permision was granted
exit 0

