#!/bin/bash

until [ -z $1 ];
do
	a=` du $1 | awk '{print $1}' `
	if [ $a == $2 ]
	then
		echo "$1 have $2"
	fi
	shift;
	shift;
done

