#!/bin/bash

D=$1

if [ -z "$D" ]; then
    echo "EROARE: Va rugam dati un director" >&2
    exit 1
fi

if [ ! -e "$D" ]; then
    echo "EROARE: Directorul dat nu exista" >&2
    exit 1
fi

if [ ! -d "$D" ]; then
    echo "EROARE: Calea data nu este director" >&2
    exit 1
fi

SUM=0
for F in `find $D -name "*.txt"`; do
    N=`wc -l $F | sed 's/ .*//'`
    SUM=`expr $SUM + $N`
done
echo $SUM
