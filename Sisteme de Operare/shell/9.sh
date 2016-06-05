#! /bin/sh

# Sa se scrie un script shell care primeste ca argument un director.
# sa se afiseze primele 5 fisiere ca si marime din interiorul lui
# inclusiv sa caute si in subdirectoare


cd $1
ls -lhSR | sort -k5 -n -r | head -n 5 
