'''
Created on Nov 11, 2014

@author: Iulian
'''
from catalog.domain.validators import StoreError

class RepositoryError(StoreError):
    pass

class Repository(object):
    def __init__(self, validator):
        self.__items = {}
        self.__validator = validator
        
    def save(self, item):
        self.__validator.validate(item)
        self.__items[item.Id] = item
    
   
        
    def delete(self, Id):
        item = self.find_by_id(Id)
        self.__validator.validate(self.__items[item.Id])
        self.__items.pop(item.Id)
        
        
    def update(self, item):
        for i in range(0, len(self.__items)):
            if i == item.Id:
                self.__items[i] = item
        self.__validator.validate(item)
    
    def size(self):
        return len(self.__items)
    
    def get_all(self):
        return list(self.__items.values())
    
    def find_by_id(self, Id):
        """Returns the item with the given Id.
        
        Exceptions:
            RepositoryError - if an item with he given Id does not exist.
        Returns: the item with the given Id.  
        """
        if not Id in self.__items:
            raise RepositoryError("an item with the given id does not exists")
        return self.__items[Id] 
    
