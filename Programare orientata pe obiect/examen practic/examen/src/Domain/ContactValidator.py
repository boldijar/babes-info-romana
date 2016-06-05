'''
Created on Jan 19, 2015

@author: Iulian
'''

class ContactValidator():
    def __init__(self):
        pass
    
    def validate(self, c, lista, nr, nume):
        '''
        valideaza un contact c
        lista - lista contactelor
        nr - numar de telefon, de verificat daca nu a mai fost introdus pentru acelasi nume
        '''
        err = []
        if c.name == "":
            err.append("numele nu poate fi vid")
        if not(c.grup =="prieteni" or c.grup == "familie" or c.grup == "job" or c.grup=="altele"):
            err.append("grupul nu este corect")
        if c.nrTel == "" :#or type(c.nrTel) is not int:
            err.append("numarul nu poate fi vid")
        for e in lista:
            if e.nrTel == nr and e.name == nume:
                err.append("Nu se pot adauga doua numere de telefon pt acelasi nume")
        
        
        return err