#!/bin/bash

until [ -z $1 ]
do
	a=`du $1 | awk ' { print $1 } ' `

	if [ $a == $2 ]; then
		echo fisierul $1 are dim data: $a 
	fi	
	shift;
	shift;
	

done
exit 0  
