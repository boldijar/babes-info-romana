#!/bin/bash

D=""
while [ ! -d "$D" ]; do
    read -p "Director:" D
done

E=""
while [ -z "$E" ]; do
    read -p "Extensie:" E
done

echo "Se numara liniile din fisierele *.$E din directorul $D" >&2

SUM=0
for F in `find $D -name "*.$E"`; do
    N=`wc -l $F | sed 's/ .*//'`
    SUM=`expr $SUM + $N`
done
echo $SUM
