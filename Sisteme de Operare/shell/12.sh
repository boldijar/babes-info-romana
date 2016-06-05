#! /bin/sh

# Scrie un script shell care citeste stringuri de la tastatura pana cand
# se introduce acelasi string de 3 ori

read x
while [ 1 -lt 3 ]; do
	read y
	if [ $x = $y ]; then
		read z
		if [ $y = $z ]; then
			exit 1
		fi
		y=$z
	fi
	x=$y
		
done
