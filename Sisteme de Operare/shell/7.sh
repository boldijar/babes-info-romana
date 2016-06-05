#! /bin/sh

# Sa se scrie un script shell care monitorizeaza continutul unui director
# dat ca si parametru si semnaleaza aparitia sau disparitia de fisiere
# sau directoare din el

prim=`ls -A $1 | wc -l`

while [ 1 -lt 3 ]; do
	if [ `ls -A $1 | wc -l` -lt $prim ]; then
		echo "Fisier sau director sters"
	elif [ `ls -A $1 | wc -l` -gt $prim ]; then
		echo "A fost creat un fisier sau director"
	fi
	prim=`ls -A $1 | wc -l`
	sleep 1
done
