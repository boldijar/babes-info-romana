#!/bin/sh

# Sa se scrie un fisier de comenzi care creeaza un fisier ce va 
# contine toate fisierele dintr-un director dat ca parametru si din 
# subdirectoarele sale pentru care membrii grupului nu au nici un fel 
# de drept. Apoi, pentru aceste fisiere, se va da drept de citire 
# pentru membrii grupului.

for x in `find $1 -type f`; do
    per=`ls -l $x | awk '{ print $1 }'`
    if [ `echo $per | grep "\-...---..."` ]; then
        echo $x
        chmod 640 $x
    fi
done | sort -u > 101_b_out.txt
