#!/bin/sh

# Sa se scrie un script shell care verifica daca un numar primit ca si 
# parametru este prim sau nu. 

prim=1
sqrt=`echo "sqrt($1)" | bc -l`

for i in `seq 2 $sqrt`; do
    if [ `echo $1%$i | bc` -eq 0 ]; then
        prim=0
        break
    fi
done

if [ $prim -eq 0 ]; then
    echo $1 is Not prime
else
    echo $1 is prime
fi