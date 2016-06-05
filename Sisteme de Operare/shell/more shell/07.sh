#!/bin/sh

# Sa se scrie un fisier de comenzi care primeste ca parametri perechi 
# formate dintr-un nume de fisier si un numar n. Pentru fiecare 
# pereche se vor afisa numele fisierului, numarul n si apoi fiecare al 
# n-lea cuvant din fiecare linie din fisier.

while [ $# -ne 0 ]; do
    file_name=$1; z=$2
    echo File name: $file_name
    echo n = $z
    res=`cat $file_name | awk -v n=$z '{ if(length($n) != 0) print $n }'`
    echo $res
    shift; shift
done