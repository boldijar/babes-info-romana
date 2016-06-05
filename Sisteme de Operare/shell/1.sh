#! /bin/sh

# Sa se scrie un fisier de comenzi care creeaza un fisier ce va contine toate
# fisierele dintr-un director dat ca parametru si din subdirectoarele sale
# pentru care membrii grupului nu au nici un fel de drept. Apoi, pentru
# aceste fisiere, se va da drept de citire pentru membrii grupului.


if [ $# -ne 1 ]; then
	echo "parametri incorecti"
	exit 1
fi

dir=$1
>a.txt
for i in `find $dir ! -perm -g=r ! -perm -g=w ! -perm -g=x`; do
	echo $i >> a.txt
done

for i in `find $dir ! -perm -g=r ! -perm -g=w ! -perm -g=x`; do
	`chmod g=r $i`
done
