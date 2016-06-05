#!/bin/sh

# Sa se scrie un script shell care primeste ca parametru un nume de 
# director si va determina numarul mediu de linii din toate fisierele 
# text din acest director si din toate subdirectoarele acestuia. Se 
# presupune ca orice director va contine doar fisiere text. 

sum=0
count=0
for x in `find $1 -type f`; do
    lines=`cat $x| wc -l`
    count=`expr $count + 1`
    sum=`expr $sum + $lines + 1` # i noticed that wc -l 
                                 # retunrs n-1 number of lines.
done
avg=`echo "scale=2; $sum/$count" | bc`
echo $avg