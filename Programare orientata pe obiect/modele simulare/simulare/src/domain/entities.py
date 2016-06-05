'''
Created on Dec 10, 2014

@author: Iulian
'''

class Bicicleta():
    def __init__(self, Id, tip, pret):
        self.__Id = Id
        self.__tip = tip
        self.__pret = pret
    
    def get_id(self):
        return self.__Id
    
    def get_tip(self):
        return self.__tip
    
    def get_pret(self):
        return float(self.__pret)
    
    def set_tip(self, value):
        self.__tip = value
    
    def set_pret(self,value):
        self.__pret = value
        
def testBicicleta():
    b = Bicicleta(1, "road", 200)
    assert b.get_id() ==1
    assert b.get_pret() ==200
    assert b.get_tip() == "road"

testBicicleta()