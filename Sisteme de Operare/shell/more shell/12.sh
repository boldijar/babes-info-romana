#!/bin/sh

# Sa se creeze un fisier care contine numele tuturor fisierelor text 
# dintr-un director dat ca parametru si din subdirectoarele acestuia 
# care au cuvinte mai lungi de n caractere (n se citeste de la 
# tastatura). Fisierul va fi ordonat alfabetic.


read -p "n = " n
for x in `find $1 -type f`; do
    for i in `cat $x`; do
        if [ ${#i} -gt $n ]; then
            file=`echo $x | awk -F "/" '{ print $NF }'`
            echo $file
            break
        fi
    done
done |sort -u > 12_out.txt