'''
Created on Dec 10, 2014

@author: Iulian
'''
from domain.entities import Bicicleta

class Repository():
    def __init__(self, nume_fis):
        self.__nume_fis = nume_fis
        
    def get_all(self):
        '''
        returneaza o lista cu toate elementele din fisier
        f - fisier
        lista = lista de elemente
        '''
        f = open(self.__nume_fis, "r")
            
        linie = f.readline().strip()
        lista = []
        while linie !='':
            atrib = linie.split(',')
            if len(atrib) == 3:
                lista.append( Bicicleta(atrib[0],atrib[1], atrib[2]))
            linie = f.readline().strip()
        f.close()
        return lista
    
    def delete(self, Id):
        '''
        functie care sterge din fisier elementele dupa un Id-ul specificat prin parametru
        '''
        f = open(self.__nume_fis, "r")
        lista = self.get_all()
        f.close()
        rez = []
        for s in lista:
            if s.get_id() != Id:
                rez.append(s)
                
        f = open(self.__nume_fis, "w")
        for s in rez:
            strB = str(s.get_id()) + "," + s.get_tip() +"," + str(s.get_pret()) + "\n"
            f.write(strB)
        f.close()
    