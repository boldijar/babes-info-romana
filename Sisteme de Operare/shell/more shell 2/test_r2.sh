#write a program that prints out the number of currently connected users and which then shows these users with their IP address spoofed using 1st argument
onlineNow=`who | wc -l`
echo "There are $onlineNow online users right now"
who > who.log

sed 's/(.*)\(.*\)/('$1')/' who.log

rm who.log
