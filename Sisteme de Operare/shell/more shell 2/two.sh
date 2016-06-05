#:sa se afiseze, pentru un user dat ca prim parametru la un program shell, ID-ul de sistem al 
#userului (nu cel al facultatii), urmat de anul si grupa din care face parte studentul, 
#excluzand masteranzi sau studenti in prelungirea

#!/bin/bash
echo "The system ID is: "
cat p.txt | grep $1 | cut -d: -f3
echo "And the year is: "
cat p.txt | grep $1 | cut -d: -f6 | cut -d\/ -f4 | cut -c4
echo "And the group is: "
cat p.txt | grep $1 | cut -d: -f6 | cut -d\/ -f4 

