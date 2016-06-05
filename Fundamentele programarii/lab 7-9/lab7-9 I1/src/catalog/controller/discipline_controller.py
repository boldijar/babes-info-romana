'''
Created on Nov 18, 2014

@author: Iulian
'''

from catalog.domain.entities import Discipline
from catalog.domain.validators import ValidatorError, StoreError

class DisciplineController(object):
    def __init__(self, repository):
        self.__repository = repository
    
    def get_all(self):
        return self.__repository.get_all()
    
    def add_discipline(self, Id, name, prof):
        try:
            s = Discipline(Id, name, prof)
            self.__repository.save(s)
        except ValidatorError as ve:
            raise StoreError(ex=ve)
        
    def delete_discipline(self, Id):
        try:
            self.__repository.delete(Id)
        except ValidatorError as ve:
            raise StoreError(ex=ve)
    
    def discipline_change(self, Id, name, prof):
        try:
            d = Discipline(Id, name, prof)
            self.__repository.update(d)
            return d
        except ValueError as ve:
            raise StoreError(ex=ve)
        
    def print_disciplines(self):
        return self.__repository.get_all()