#! /bin/sh

#105. b)
#Sa se scrie un fisier de comenzi care preia un fisier de intrare dat ca
#parametru si creeaza din el un alt fisier (al carui nume este dat ca
#parametru) in care pastreaza doar cuvintele care contin litere mici.
#Fisierul se va ordona alfabetic. Daca in rezultat exista linii consecutive
#identice, se va pastra doar una dintre ele.
#


if [ $# -ne 2 ]; then
	echo "parametri incorecti"
	exit 1
fi

bool=0

for i in `sed "s/\<[A-Z]*\>//g" $1 | sort | uniq`; do
	if [ $bool -eq 0 ]; then
		echo $i > $1
		bool=$((bool+1))
	else
		echo $i >> $1
	fi	
done

`mv $1 $2`
