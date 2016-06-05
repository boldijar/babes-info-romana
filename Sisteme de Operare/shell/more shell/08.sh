#!/bin/sh

# Sa se scrie un script shell care citeste continuu cuvinte de la 
# tastatura si le sterge din toate fisierele date ca si parametri.

while [ 0 -lt 1 ]; do
    read -p "Enter word: " word
    for x in $@; do
        sed -i "s/\<$word\>//g" $x
    done
done