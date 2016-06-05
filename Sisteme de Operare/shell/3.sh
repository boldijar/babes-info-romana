#! /bin/sh

# Sa se scrie un script shell care monitorizeaza aparitia in toate directoarele
# date ca si parametru in linia de comanda a unui nume de fisier citit de la 
# tastatura.

echo "nume fisier: "
read nume

for i in $@; do		# pentru fiecare parametru
	gasit=0
	for j in `ls $i`; do	#pentru fiecare fisier j din directorul i
		# daca gasim fisierul cu numele dat atunci il afisam
		if [ $j = $nume ]; then
			echo "$nume apare in $i"
			gasit=1
		fi
	done	
	# daca fisierul nu apare in directorul i
	if [ $gasit -eq 0 ]; then
		echo "$nume nu apare in $i"
	fi
done
