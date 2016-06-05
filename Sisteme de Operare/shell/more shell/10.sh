#!/bin/sh

# Sa se scrie un fisier de comenzi care primeste ca parametri perechi 
# formate din nume de fisier si un numar. Pentru fiecare astfel de
# pereche se va verifica daca dimensiunea fisierului coincide cu 
# numarul respectiv, si se va afisa un mesaj corespunzator.

while [ $# -ne 0 ]; do
    size=`ls -l $1 | awk '{ print $5 }'`
    if [ $size -eq $2 ]; then
        echo Yes, $1 has exactly $2 bytes
    else
        echo No, $1 does not have exactly $2 bytes
    fi
    shift; shift
done
