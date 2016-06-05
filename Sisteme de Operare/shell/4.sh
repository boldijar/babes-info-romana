#! /bin/sh

# Sa se scrie un fisier de comenzi care are ca parametri triplete
# formate dintr-un nume de fisier, un cuvant si un numar k. Pentru fiecare 
# astfel de triplet, se vor afisa toate liniile fisierului care contin
# cuvantul respectiv exact de k ori.

if [ $# -ne 3 ]; then
	echo "parametrii incorecti"
	exit 1
fi

fis=$1		# fisier
cuv=$2		# cuvantul dat ca parametru
k=$3		

#lfis=`cat $fis`	# liniile din fisierul fis

while read line; do	# cat timp putem citi o linie din fisierul $fis	
	n=0	# contor pentru cuvintele de pe o linie ce sunt egale cu $cuv
	for word in $line; do	# pentru fiecare cuvant din linie
		if [ $word = $cuv ]; then	# daca e egal cu cuvantul dat
			n=$(($n+1))	# marim contor
		fi
	done
	if [ $n -eq $k ]; then		# daca contor egal cu k, afisam linia
		echo $line
	fi
	
done<$fis

