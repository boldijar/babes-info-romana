#!/bin/sh

# Sa se scrie un script shell care tot citeste utilizatori din linia de 
# comanda si pentru fiecare utilizator afiseaza numele real al 
# acestuia, numarul de procese (daca are) si ce comenzi ruleaza.

while [ 3 -lt 5 ]; do
    read -p "Enter user name: " user
    pcs=`ps -ef | grep "^$user" | wc -l`
    echo User $user has $pcs running processes
    echo List of running processes \(no duplicates\):
    ps -ef | grep "^$user" | awk '{ print  $1" "$2" "$8 }' | sort -u -k3,3
    echo
done