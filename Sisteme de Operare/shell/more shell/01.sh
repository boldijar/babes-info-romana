#!/bin/sh

# Sa se scrie un script shell care face topul primilor utilizatorilor 
# conectati la server dupa numarul de procese pe care le ruleaza. 
# Topul se va afisa pe ecran la fiecare s secunde (s parametru in 
# linia de comanda) pentru primii n utilizatori din top (n se citeste 
# de la tastatura la pornirea scriptului).

s=$1
read -p "n = " n
while [ 3 -lt 5 ]; do
    ps -ef | awk '{ print $1 }' | sort | uniq -c | sort -r -n | head -$n
    echo
    sleep $s
done