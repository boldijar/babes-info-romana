'''
Created on Nov 11, 2014

@author: Iulian
'''
from catalog.domain.entities import Student
from catalog.domain.validators import StoreError, ValidatorError

class StudentController(object):
    def __init__(self, repository):
        self.__repository = repository
    
    def get_all(self):
        return self.__repository.get_all()
    
    def add_student(self, Id, name):
        s = Student(Id, name)
        try:
            self.__repository.add_item(s)
        except ValidatorError as ve:
            raise StoreError(ex=ve)
    
    def delete_student(self, Id):
        try:
            self.__repository.delete(Id)
        except ValidatorError as ve:
            raise StoreError(ex=ve)
    
    def find_student(self, Id):
            try:
                return self.__repository.find_by_id(Id)
            except ValidatorError as ve:
                raise StoreError(ex=ve)
              
    def print_students(self):
        return self.__repository.get_all()