# write a shell script that prints on screen the sum of all
# natural numbers from files given as parameter.
# Remark: "4,2" should be treated as "4 2"
#         "4.2" it's floating point number and should be ignored
#!/bin/bash
sum=0
for fis in $@
do
if [ -f $fis ]
then
	sed -i 's/,/ /' $fis
	for item in `cat $fis`
	do
		
		if [[ $item =~ ^[0-9]*'.'?$ ]] 
		then
			
			nr=`echo $item | tr -d . `
			sum=` expr $sum + $nr `  
		fi
	done	
else
echo $fis is not a file
fi
done
echo the sum is $sum
