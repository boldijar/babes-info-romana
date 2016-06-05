#! /bin/sh

# Scrie un script shell care citeste stringuri de la tastatura pana cand
# se introduc 3 nume de fisiere

while [ 1 -lt 3 ]; do
	read x
	if [ -f $x ]; then
		read y
		if [ -f $y ]; then
			read y
			if [ -f $y ]; then
				exit 1
			fi
		fi
	fi
done
