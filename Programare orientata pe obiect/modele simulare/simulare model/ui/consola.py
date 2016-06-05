'''
Created on 8 dec. 2014

@author: teo
'''

class Console():
    
    def __init__(self, contr):
        self.__cont = contr
        
    def __citireDate(self):
        id = int(input("Introduceti ID-ul."))
        titlu = input("Introduceti titlul.")
        pret = float(input("Introduceti pretul."))
        nrLocuri = int(input("Introduceti numarul de locuri."))
        
        return (id, titlu, pret, nrLocuri)
    
    def __afisare(self):
        '''
        afiseaza toate filmele din fisier
        '''
        lista = self.__cont.getAll()
        
        for fi in lista:
            print(fi.getID()," ", fi.getTitlu()," ", fi.getPret()," ", fi.getNrLocuri())
        
    def showUI(self):
        '''
        afiseaza itemii meniului
        '''
        while(True):
            print("1.Afisati filmele.\n\
            2. Actualizati un film.\n\
            3. Iesire\n\n")
            
            item = input("Introduceti itemul dorit: ")
            
            try:
                if item == "1":
                    self.__afisare()
                if item == '2':
                    id, titlu, pret, nrLocuri = self.__citireDate()
                    self.__cont.update(id, titlu, pret, nrLocuri)
                if item == '3':
                    break
            except ValueError as msg:
                print(msg)
            except AttributeError as msg:
                print (msg)
            
        
        