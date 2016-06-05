#!/bin/sh

# Sa se scrie un fisier de comenzi care are ca parametri triplete
# formate dintr-un  nume de fisier, un cuvant si un numar k. Pentru
# fiecare astfel de triplet, se vor afisa toate liniile fisierului care
# contin cuvantul respectiv exact de k ori.

while [ $# -ne 0 ]; do
    file_name=$1; word=$2; k=$3
    while read line; do
        n=`echo $line | grep -o "$word" | wc -l`
       if [ $n -eq $k ]; then
            echo $line
       fi
    done < $file_name  
    shift; shift; shift
done