#!/bin/bash
if [ `find . -name $1 -type f` ]; then
	echo `stat --format "%s" $1`
elif [ `find . -name $1 -type d` ]; then
	echo `find $1 -name \*.txt | wc -l`
fi
