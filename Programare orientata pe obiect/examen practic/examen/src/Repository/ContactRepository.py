'''
Created on Jan 19, 2015

@author: Iulian
'''
from Domain.Contact import Contact

class Repository():
    def __init__(self, filename):
        self.__filename = filename
    
    def get_all(self):
        '''
        returneaza o lista cu toate contactele din fisier
        '''
        f = open(self.__filename, 'r')
        lista = []
        linie = f.readline().strip()
        while linie !="":
            arr = linie.split()
            if len(arr) == 4:
                lista.append(Contact(int(arr[0]), arr[1], int(arr[2]), arr[3]))
            linie =f.readline().strip()
        f.close()
        return lista
    
    def get_all_for_group(self, grup):
        '''
        returneaza o lista cu contactele din fisier cu grupul grup
        '''
        f = open(self.__filename, 'r')
        lista = []
        linie = f.readline().strip()
        while linie !="":
            arr = linie.split()
            if len(arr) == 4 :
                if arr[3] == grup:
                    lista.append(Contact(int(arr[0]), arr[1], int(arr[2]), arr[3]))
            linie =f.readline().strip()
        f.close()
        return lista
    
    def add(self, c):
        '''
        adauga contactul c in fisier
        '''
        try:
            with open(self.__filename, "a") as f:
                s = str(c.Id) + " " + c.name + " " + str(c.nrTel) + " " + c.grup + "\n"
                f.write(s)
               
        except IOError:
            return None
    
    def export(self, c):
        '''
        salveaza in fisierul CSV.txt contactul c
        '''
        try:
            with open("CSV.txt", "a") as f:
                s = c.name + "," + str(c.nrTel) +"\n"
                f.write(s)
        except IOError:
            return None
        
    
    def find(self, name):
        '''
        cauta contactul cu numele dat
        returneaza contactul
        '''
        f = open(self.__filename, 'r')
        for linie in f:
            while linie !='':
                arr = linie.split()
                if arr[1] == name:
                    return Contact(int(arr[0]), arr[1], int(arr[2]), arr[3])
        f.close()
        return None