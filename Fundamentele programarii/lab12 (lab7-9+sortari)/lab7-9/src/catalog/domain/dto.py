'''
Created on Nov 27, 2014

@author: Iulian
'''


class StudentDisciplineAssembler(object):
    
    @staticmethod
    def create_student_discipline_dto(Id, student, discipline, grade):
        return StudentDisciplineDTO(Id, student.name , discipline.Discipline_name, grade )
    
class StudentDisciplineDTO(object):
    def __init__(self, Id, student_name, discipline_name, grade):
        self.__Id = Id
        self.__student_name = student_name
        self.__discipline_name = discipline_name
        self.__grade = grade
        
    @property 
    def Id(self):
        return self.__Id
    
    @property
    def student_name(self):
        return self.__student_name
    
    @property
    def discipline_name(self):
        return self.__discipline_name
        
    @property
    def grade(self):
        return self.__grade
    
    @grade.setter
    def grade(self, value):
        self.__grade = value
         
    def __str__(self):
        return str(self.Id) + ". " + self.student_name + " - " + self.discipline_name + ": " + str(self.grade)

