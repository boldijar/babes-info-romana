#! /bin/sh

# Sa se scrie un script shell care face topul primilor utilizatori conectati
# la server dupa numarul de procese pe care le ruleaza.
# Topul se va afisa pe ecran la fiecare s secunde (s parametru in linia
# de comanda) pentru primii n utilizatori din top (n se citeste de la 
# tastatura la pornirea scriptului

s=$1

read -p "n=" n

while [ 1 -lt 2 ]; do
	ps -ef | awk '{print $1}' | sort | uniq -c | sort -n -r | head -$n
	echo
	sleep $s
done
