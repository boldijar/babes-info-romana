#!/bin/sh
 
# Write a shell script that prints on screen the sum of all
# natural numbers from files given as parameter.
# Remark: "4,2" should be treated as "4 2"
#         "4.2" it's floating point number and should be ignored
 
sum=0
for x in $@; do
    sed -i 's/,/ /g' $x
    for y in `cat $x`; do
        if [ $y -eq $y 2> /dev/null ] && [ $y -gt 0 ]; then
            sum=`expr $sum + $y`
        fi
    done
done
echo $sum