#! /bin/sh

# Sa se scrie un program shell care primeste nume de utilizatori ca si
# argumente si pentru fiecare calculeaza numarul de login-uri in zile 
# de luni (folositi comanda "last"). scriptul va afisa utilizatorii si
# numerele calculate in ordinea inversa a numerelor

for i in $@; do
	count=`grep $i last.fake | grep -c Mon`
	echo $i $count
done | sort -k2 -r
