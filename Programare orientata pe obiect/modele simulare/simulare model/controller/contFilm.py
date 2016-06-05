'''
Created on 8 dec. 2014

@author: teo
'''
from repository.repo import RepoFilme
from domain.filme import Film
from domain.validator import Validator


class ControllerFilm():
    '''
    clasa care manage-uieste operatiile pe filme
    '''
    def __init__(self, repo, valid):
        self.__repo = repo
        self.__valid = valid
        
    def getAll(self):
        '''
        returneaza toate filmele din fisier sau None daca nu este niciun film in fisier
        '''
        lista = self.__repo.getAll()
        if lista == None:
            raise ValueError("Fisierul este gol.")
        
        return self.__repo.getAll()
    
    def update(self, id, titlu, pret, nrLocuri):
        '''
        clasa care updateaza un film
        id - idul filmului de modificat
        titlu, pret, nrLocuri - datele noi pt filmul de modificat
        arunca ValueError daca datele nu sunt valida
        arunca AttributeError daca nu exista ID-ul introdus
        '''
        fi = Film(id, titlu, pret, nrLocuri)
        
        self.__valid.validare(fi)
        
        self.__repo.modificare(fi)

def testUpdateController():
    open("filmetest.txt", 'w')
    repo = RepoFilme("filmetest.txt")
    repo.update(Film(47, 'De la specii', 15, 68))
    repo.update(Film(49, 'De la speci', 17, 85))
    valid = Validator()
    
    cont = ControllerFilm(repo, valid)
    cont.update(47, 'De la speci', 17, 85)
    lista = cont.getAll()
    assert lista == [ Film(47, 'De la speci', 17, 85), Film(49, 'De la speci', 17, 85)]
    
    
testUpdateController()