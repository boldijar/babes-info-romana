#Sa se afiseze, pentru un user citit de la tastatura intr-un program shell, numele si 
#prenumele userului, urmat apoi de o lista de stundeti cu nume similar afisati sub forma 
#username nume prenume

echo "input username"
read user

echo "fullname: "
cat /etc/passwd | grep $user | cut -d: -f5
echo "family name: "
name=`cat /etc/passwd | grep $user | cut -d: -f5 | cut -d" " -f1`
echo $name

echo "similar users: "
cat /etc/passwd | grep $name | cut -d: --output-delimiter=" " -f1,5
