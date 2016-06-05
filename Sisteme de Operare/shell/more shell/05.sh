#!/bin/sh

# Sa se scrie un script shell care primind 3 parametri, (extensie1, 
# extensie2, cuvant) va redenumi toate fisierele cu extensia 
# extensie1 din directorul curent si din toate subdirectoarele 
# acestuia, dandu-le extensia extensie2 si va numara de cate ori 
# apare cuvant in fiecare fisier.

for x in `find $(pwd) -type f `; do
    ext=`echo $x | awk -F "." '{ print $NF }'`
    if [ $ext = $1 ]; then
        x2=`echo $x | sed "s/\.$1$/\.$2/"`
        mv $x $x2
        echo $x2
        n=`grep -o "$3" $x2 | wc -l`
        echo \"$3\" appears $n times \in the above file 
    fi
done