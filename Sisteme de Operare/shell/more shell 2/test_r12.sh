#!/bin/bash
#sa se afiseze, pentru un user dat ca prim parametru la un program shell, ID-ul de sistem al 
#userului (nu cel al facultatii), urmat de anul si grupa din care face parte studentul, 
#excluzand masteranzi sau studenti in prelungire

cat /etc/passwd:q | grep $1 | cut -d: -f3
an=`cat /etc/passwd | grep $1 | cut -d: -f6 | cut -d\/ -f5`
grupa=`cat /etc/passwd | grep $1 | cut -d: -f6 | cut -d\/ -f6`

if [[ "$grupa" =~ ^gr.*$ ]];
then
	echo $an
	echo $grupa
else
	echo "nu e student cu grupa"
fi
