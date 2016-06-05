'''
Created on Dec 10, 2014

@author: Iulian
'''


class Bicicleta_controller():
    def __init__(self, repo):
        self.__repo = repo
    
    def sterge_tip(self, tip):
        lista = self.__repo.get_all()
        for s in lista:
            if s.get_tip() == tip: 
                self.__repo.delete(s.get_id())
            
    def sterge_max(self):
        lista = self.__repo.get_all()
        pret_max = 0
        for s in lista:
            if s.get_pret() > pret_max:
                pret_max = s.get_pret()
        
        for s in lista:
            if s.get_pret() == pret_max:
                self.__repo.delete(s.get_id())
