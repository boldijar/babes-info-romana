#!/bin/sh

# Sa se scrie un script shell care monitorizeaza continutul unui 
# director dat ca si parametru si semnaleaza aparitia sau disparitia 
# de fisiere sau directoare din el.

past=`ls -A $1 | wc -l`
while [ 3 -lt 5 ]; do
    if [ `ls -A $1 | wc -l` -gt $past ]; then
       echo New file/folder has been created!
    elif [ `ls -A $1 | wc -l` -lt $past ]; then
       echo File/Folder has been deleted!
    fi
    past=`ls -A $1 | wc -l`
    sleep 1
done