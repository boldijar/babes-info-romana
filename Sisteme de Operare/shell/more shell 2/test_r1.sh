#!/bin/bash
# write a program that prints out the total number of logins currently logged in the system's history, for a user given as 1st parameter. Also print terminal and IP address for all users that were online and who's 
#username match the regex given as second param

loggedTimes=`last | grep $1 | wc -l`;
echo "user $1 logged in $loggedTimes into the system";



awk -v reg="$2" '{ if($1 ~ reg) print $1 " logged in " $2 " " $3;}' last.fake.txt


