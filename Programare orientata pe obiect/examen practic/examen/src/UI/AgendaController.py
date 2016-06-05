'''
Created on Jan 19, 2015

@author: Iulian
'''
from Domain.Contact import Contact
from Domain.ContactValidator import ContactValidator
from Repository.ContactRepository import Repository

class Controller():
    def __init__(self, repo):
        self.__repo = repo
    
    def adaugare_contact(self, Id, nume, nr, grup):
        '''
        functia adauga un contact in fisierul ,,agenda.txt" sau returneaza o 
        lista de erori daca datele sunt introduse gresit
        parametrii sunt datele contactului
        c - Contact
        v - validator
        er - lista de erori dupa validare        
        '''
        c = Contact(Id, nume, nr, grup)
        v = ContactValidator()
        l = self.__repo.get_all()
        try:
            er = v.validate(c,l, nr, nume)
            
            if len(er) != 0:
                return er
            else:
                self.__repo.add(c)
                return []
        except ValueError:
            return er
    
    def lookup(self, nume):
        '''
        returneaza contactul cu numele dat ca parametru
        '''
        l = self.__repo.get_all()
        for e in l:
            if e.name == nume:
                return e
    
    def ordonare(self,l):
        ''' ordonare crescatoare dupa nume
        '''
        for i in range(0,len(l)):
            for j in range(i, len(l)):
                if l[i].name > l[j].name:
                    aux = l[i]
                    l[i] = l[j]
                    l[j] = aux
    
    def lookupAll(self, grup):
        ''' 
        returneaza o lista cu toate contactele de un anumit grup
        '''
        l = self.__repo.get_all_for_group(grup)
#         rez = []
#         for e in l:
#             if e.grup == grup:
#                 rez.append(e)
        
        self.ordonare(l)
        return l
        
    def exporta(self, grup):
        '''
        exporta in fisierul CSV.txt numele si numarul de telefon al persoanelor cu grupul dat
        '''
        l = self.lookupAll(grup)
        if l == []:
            return None
        for e in l:
            self.__repo.export(e)
        return 1

def test_lookupAll():
    repo = Repository("test.txt")
    c = Controller(repo)
    rez = c.lookupAll("prieteni")
    assert len(rez) == 2
    rez = c.lookupAll("job")
    assert len(rez) == 3
    

def test_lookup():
    repo = Repository("test.txt")
    contr = Controller(repo)
    c = contr.lookup("alin")
    assert c==None
    
    c = contr.lookup("c4")
    assert c!= None

def test_ordonare():
    l = [Contact(1, "tomi", 454, "prieteni"), Contact(4, "ana", 424, "prieteni") ]
    repo = Repository("test.txt")
    c = Controller(repo)
    c.ordonare(l)
    assert l[0].name == "ana"
    assert l[1].name == "tomi"

# test_lookupAll()
# test_lookup()
# test_ordonare()