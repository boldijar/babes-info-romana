'''
Created on Jan 19, 2015

@author: Iulian
'''
#from Domain.Contact import Contact

class Consola():
    def __init__(self, contr):
        self.__contr = contr
    
    def adaugareUI(self):
        Id = int(input("ID: "))
        nume = input("Nume: ")
        nr = int(input("nr telefon: "))
        grup = input("Grup: ")
        ''' a - lista
        '''
        a = self.__contr.adaugare_contact(Id, nume, nr, grup)
        if(len(a) != 0):
            for el in a:
                print(el)
        if( len(a) == 0):
            print("Contact adaugat cu succes")
            
    def tiparire(self):
        grup = input("Grup: ")
        l = self.__contr.lookupAll(grup)
        
        if len(l) == 0:
            print("Nu exista")
        else:
            for e in l:
                print (e)
    
    def cauta(self):
        nume = input("Nume: ")
        c = self.__contr.lookup(nume)
        if c == None:
            print("Nu exista")
        else:
            print(c)
    
    def exporta(self):
        g = input("Grup: ")
        l = self.__contr.exporta(g)
        if l==None:
            print("Nu exista contacte in grupul dat")
        
    def run(self):
        optiuni = {1:self.adaugareUI,2:self.cauta, 3:self.tiparire, 4:self.exporta}
        while True:
            print("            1.Adaugare contact \n\
            2. Cautare numar de telefon pentru un nume dat\n\
            3. tipareste toate contactele pentru un grup dat ordonat dupa nume\n\
            4. exporta toate contactele pentru un grup dat intr-un fisier CSV.txt\n\
            5. iesire")
            try:
                op= int(input("Optiune: "))
                if op == 5:
                    break
                optiuni[op]()
            except ValueError:
                print("Optiune gresita")