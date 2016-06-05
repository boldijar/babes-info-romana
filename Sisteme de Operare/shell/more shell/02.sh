#!/bin/sh

# Sa se scrie un script shell care monitorizeaza aparitia in toate 
# directoarele date ca si parametru in linia de comanda a unui nume 
# de fisier citit de la tastatura.

read -p "Enter file name: " file
while [ 3 -lt 5 ]; do
    for x in $@; do
        cd $x
        if [ -e $file ]; then 
            echo $file was found \in $x
            break 2
        fi
        sleep 1
    done
done