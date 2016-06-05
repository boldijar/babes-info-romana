#71. b)
#Write a shell script that continuously reads user names from keyboard and
#for each of them outputs its full name, the number of processes and the
#current running command.
echo read user name: 
read x
until [ -z $x ]
do

	if grep $x passwd.fake.txt
	then
		echo The name is:
		cat passwd.fake.txt | grep $x | cut -d: -f5

		echo The number of processe is:
		ps -ef | grep $x | cut -d" " -f1 | wc -l
		echo The processes are:
		w | awk -v user="$x"  'match($1,user)  { print $8  }'
		
	else
		echo no such user
	fi




	echo read user name: 
	read x
done
