#Sa se numere in cate fisiere (date ca si parametrii) apare primul cuvant dat ca si parametru
#!/bin/bash
count=0
cuv=$1
shift
until [ -z $1 ]
do
	if [ -f $1 ]
	then
		if grep -q $cuv $1
		then
			count=$(( count +1 ))
		fi
		shift
	else
		echo $1 nu este un fisier
		shift		
	fi

done

echo cuvantul $cuv apare in $count fisiere
