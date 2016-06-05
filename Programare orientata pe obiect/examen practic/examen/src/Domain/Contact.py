'''
Created on Jan 19, 2015

@author: Iulian
'''

class Contact():
    def __init__(self, Id, name, nrTel, grup):
        self.__Id = Id
        self.__name = name
        self.__nrTel = nrTel
        self.__grup = grup
    
    @property
    def Id(self):
        return self.__Id
    
    @property
    def name(self):
        return self.__name
    
    @property
    def nrTel(self):
        return self.__nrTel
    
    @property
    def grup(self):
        return self.__grup
    
    @Id.setter
    def Id(self, value):
        self.__Id = value
    
    @name.setter
    def name(self, value):
        self.__name = value
    
    @nrTel.setter
    def nrTel(self, value):
        self.__nrTel = value
    
    @grup.setter
    def grup(self, value):
        self.__grup = value
    
    def __str__(self):
        return str(self.Id)+ " " + self.name + " " + str(self.nrTel) +" "+ self.grup + "\n"
    
def test():
    contact = Contact(1,"abc", 789, "Prieteni")
    assert contact.Id ==1
    assert contact.name=="abc"
    assert contact.nrTel == 789
    assert contact.grup == "Prieteni"

test()
    