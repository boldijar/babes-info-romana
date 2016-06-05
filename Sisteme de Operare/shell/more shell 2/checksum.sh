#Write a script that takes a large file, cuts it into smaller pieces, and uploads all the pieces to a server (in our case it is easier to just copy all the pieces to a different location). Write a second script that checks whether all the pieces were copied correctly and none of them were corrupted during the transfer, and then concatenates the pieces to obtain the original large file. Hint: create an extra text file containing the checksums of each piece and transfer it along with the pieces; then use it to check for corruption
#!/bin/bash
a=`wc -l $1`
a=(`echo $a | tr ' ' ' '`)
a=$(( a / 10 ))

split -l $a $1 myfiles
count1=0
for item in `find  myfile*`
do 
	md5sum $item >> checksum.txt
	count1=$((count1 +1))
done
mv myfiles* ./newdir
mv checksum.txt ./newdir
count2=0 
for item in `ls newdir`
do
	if [[ $item =~ ^my* ]]
	then
		b=`md5sum ./newdir/$item | awk '{ print $1 }'`
		if grep $b ./newdir/checksum.txt  
		then
			count2=$(( count2 + 1 ))
		fi
	
	fi
done
echo "$count2 / $count1 files  was transmited"
