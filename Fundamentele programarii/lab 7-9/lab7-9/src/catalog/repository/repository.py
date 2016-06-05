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
        
    def add_item(self, item):
        self.__validator.validate(item)
        self.__items[item.Id] = item
        
    def delete(self, Id):
        item = self.find_by_id(Id)
        self.__validator.validate(self.__items[item.Id])
        self.__items.pop(item.Id)
             
    def update(self, item):
        self.__validator.validate(item)
        for i in range(0, len(self.__items)):
            if i == item.Id:
                self.__items[i] = item
        
    
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
        

'''        
class StudentDisciplineRepository(object):
    def __init__(self, validator):
        self.__itemsL = []
        self.__validator = validator
        
    def saveSD(self, item):
        self.__validator.validate(item)
        self.__itemsL.append(item)
    
    def updateList(self, item):
        poz = -1
        self.__validator.validate(item)
        for i in range(len(self.__itemsL)):
            st_di = self.__itemsL[i]
            if st_di.get_discipline()==item.get_discipline() and st_di.get_student()==item.get_student():
                poz = i
        if poz==-1:
            raise ValueError("Nu exista asociere intre cadru si disciplina")
        self.__itemsL[poz] = item
        
    def get_all_list(self):
        return self.__itemsL
    
    def f_average(self, discipline):
        average = 0
        c=0
        for e in range(0, len(self.__itemsL)):
            if self.__itemsL[e].get_discipline().get_discipline_name() == discipline:
                average = average + e.get_grade()
                c = c+1
        average = average / c
        return average
    
    def sort_discipline(self, discipline, average):
        average = self.f_average(discipline)
        for i in range(0, len(self.__itemsL)):
            pass
'''
