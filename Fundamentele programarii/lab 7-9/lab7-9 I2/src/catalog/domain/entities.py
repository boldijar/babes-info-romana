'''
Created on Nov 11, 2014

@author: Iulian
'''

class Student(object):
    def __init__(self, student_id, student_name):
        self.__student_id = student_id
        self.__student_name = student_name
    
    def get_student_id(self):
        return self.__student_id
    
    def get_student_name(self):
        return self.__student_name
    
    def set_student_name(self, value):
        self.__student_name = value
    
    Id = property(get_student_id, None, None, "student_id's docstring")
    name = property(get_student_name, set_student_name, None, "student_name's docstring")
    
    def __str__(self):
        return str(self.Id) + ". " + self.name


class Discipline(object):
    def __init__(self, discipline_id, discipline_name, discipline_prof):
        self.__discipline_id = discipline_id
        self.__discipline_name = discipline_name
        self.__discipline_prof = discipline_prof
    
    def get_discipline_id(self):
        return self.__discipline_id
    
    
    def get_discipline_name(self):
        return self.__discipline_name
    
    def set_discipline_name(self, value):
        self.__discipline_name = value
    
    
    def get_discipline_prof(self):
        return self.__discipline_prof
    
    def set_discipline_prof(self, value):
        self.__discipline_prof = value
    
    Id = property(get_discipline_id, None, None, "Discipline_id's docstring")
    Discipline_name = property(get_discipline_name, set_discipline_name, None, "Discipline_name's docstring")
    Discipline_prof = property(get_discipline_prof, set_discipline_prof, None, "Discipline_prof's docstring")
    
    def __str__(self):
        return str(self.Id) + ". " + self.Discipline_name + " - " + self.Discipline_prof


