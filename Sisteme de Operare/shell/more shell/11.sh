#!/bin/sh

# Sa se afiseze, pentru fiecare fisier luat ca si parametru din linia de 
# comanda, numarul de cuvinte care au lungimea mai mare decat un 
# numar k, citit de la tastatura. Afisarea se va face decsrescator 
# dupa numarul de cuvinte.



read -p "k = " k
for x in $@; do
    c=0
    for y in `cat $x`; do
        if [ ${#y} -gt $k ]; then
            c=`expr $c + 1`
        fi
    done
    echo $c words of length $k+1 were found \in $x
done | sort -r -u