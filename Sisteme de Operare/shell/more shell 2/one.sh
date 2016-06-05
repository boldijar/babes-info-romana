#write a program that prints out the total number of logins currently logged in the system's history, for a user given as 1st parameter. Also print terminal and IP address for all users that were online and who's 
#-username match the regex given as second param
#!/bin/bash

if [ -z $2 ]; then
	echo please insert 2 param
	exit 1
fi

grep $1 last.fake.txt | wc -l
echo $2
awk -v reg="$2" ' match($1,reg){  print $1" logged at "$3  } ' last.fake.txt
