'''
Created on Nov 18, 2014

@author: Iulian
'''

class StoreError(Exception):
    def __init__(self, message=None, ex=None):
        Exception.__init__(self, message)
        self.__ex = ex
        self.__message = message
    
    @property
    def message(self):
        msg = self.__message if self.__message else ""
        if self.__ex is None:
            return msg
        msg = msg + " " + type(self.__ex).__name__ + ": " + str(self.__ex)
        return msg
     
    def __str__(self):
        return self.message

class ValidatorError(StoreError):
    pass

class StudentValidator(object):
    def validate(self, st):
        errors = []
        if not type(st.Id) is int or st.Id <= 0:
            errors.append("Student Id must be an int greater or equal to 1")
        if not st.name:
            errors.append("Name must be a non-empty string")
       
        if len(errors) > 0:
            raise ValidatorError(str(errors)) 

class DisciplineValidator(object):
    def validate(self, di):
        errors = []
        if not type(di.Id) is int or di.Id<= 0:
            errors.append("Discipline Id must be an int greater or equal to 1")
        if not di.Discipline_name:
            errors.append("Discipline name must be a non-empty string")
        if not di.Discipline_prof:
            errors.append("Professor name must be a non-empty string")
            
        if len(errors) > 0:
            raise ValidatorError(str(errors)) 
        
class StudentDisciplineValidator(object):
    def validate(self,st_di):
        errors = []
        if not type(st_di.get_student_discipline_id()) is int or st_di.get_student_discipline_id() < 0:
            errors.append("Student-Discipline id must pe an int greater or equal to 1")
        if not type(st_di.get_student_id()) is int and not type(st_di.get_student_id()) < 0:
            errors.append("Student Id must be an int greater or equal to 1")
        if st_di.get_discipline_id() < 0 and not type(st_di.get_discipline_id()) is int:
            errors.append("Discipline Id must be an int greater or equal to 1")
        if st_di.get_grade() < 0 or st_di.get_grade() > 10:
            errors.append("Nota trebuie sa fie in intervalul [0,10]")
            
        if len(errors)>0:
            raise ValidatorError(str(errors))
