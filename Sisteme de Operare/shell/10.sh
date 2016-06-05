#! /bin/sh

# Se citesc stringuri pana se gaseste un fisier din directorul curent
# care are toate permisiunile la user


while [ 1 -lt 3 ]; do
	read i
	v=`find $i -perm -u=r -perm -u=w -perm -u=x`
	if [ "$v" = "$i" ]; then
		exit 1
	fi
done
