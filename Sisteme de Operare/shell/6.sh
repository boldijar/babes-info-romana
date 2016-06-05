#! /bin/sh

# Sa se scrie un script shell care monitorizeaza aparitia in toate
# directoarele date ca si parametru in linia de comanda a unui nume
# de fisier citit de la tastatura

read -p "nume fisier: " nume
for x in $@; do
	cd $x
	if [ -e $nume ]; then
		echo "fisierul $nume a fost gasit in $x"
					
	fi	
	cd ..
done
