#Sa se scrie un script shell care verifica daca un numar primit ca si
#parametru este prim sau nu.

#!/bin/bash

nr=$1

if [[ ! "$nr" =~ ^[0-9]*$  ]]
then
	echo nu ati dat un numar
	exit 1
fi

d=2
half=$(( nr / 2))
while [ $d -le $half ];
do
	re=$((nr%d))
	if [ $re -eq 0 ]
	then
		echo numarul nu este prim
		exit 0
	fi
	d=$((d+1))
	echo numarul este prim
	exit 0
done	
