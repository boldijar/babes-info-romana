#!/bin/bash

for A in $@; do
    echo Avem $A
done

for A; do
    echo Avem $A
done

echo $@
shift
echo $@
shift 2
echo $@
shift 3
echo $@


#for A in catel pisica purcel; do
#    echo Avem $A
#done

#for A in ../02/*.txt; do
#    file $A
#done

#for A in `find ~ -name "*.txt"`; do
#    file $A
#done
