'''
Created on Nov 19, 2014

@author: Iulian
'''
import unittest
from catalog.domain.validators import StudentValidator, ValidatorError,\
    DisciplineValidator, StudentDisciplineValidator
from catalog.domain.entities import Student, Discipline, Student_Discipline

class StudentValidatorTestCase(unittest.TestCase):
    def test_validate(self):        
        sv = StudentValidator()
        s = Student(1, "s1")
        try:
            sv.validate(s)
            assert(True)
        except ValidatorError:
            assert(False)
        
        s = Student(1, "")
        try:
            sv.validate(s)
            assert(False)
        except ValidatorError:
            assert(True)

class DisciplineValidatorTestCase(unittest.TestCase):
    def test_validate(self):        
        dv = DisciplineValidator()
        d = Discipline(1, "d1", "p1")
        try:
            dv.validate(d)
            assert(True)
        except ValidatorError:
            assert(False)
        
        d = Discipline(1, "", "")
        try:
            dv.validate(d)
            assert(False)
        except ValidatorError:
            assert(True)
          
class StudentDisciplineValidatorTestCase(unittest.TestCase):
    def test_validate(self):
        sv = StudentValidator()
        dv = DisciplineValidator()
        sdv = StudentDisciplineValidator()
        s = Student(1, "s1")
        d = Discipline(1, "d1", "p1")
        d1s1 = Student_Discipline(10,s.get_student_id() , d.get_discipline_id(),5)
        try:
            sv.validate(s)
            dv.validate(d)
            sdv.validate(d1s1)
            assert True
        except ValidatorError:
            assert False
        
        sv = StudentValidator()
        dv = DisciplineValidator()
        sdv = StudentDisciplineValidator()
        s = Student(1, "")
        d = Discipline(1, "", "")
        d1s1 = Student_Discipline(2, s.get_student_id() ,d.get_discipline_id(),5)
        try:
            sv.validate(s)
            dv.validate(d)
            sdv.validate(d1s1)
            assert False
        except ValidatorError:
            assert True
        
        sv = StudentValidator()
        dv = DisciplineValidator()
        sdv = StudentDisciplineValidator()
        s = Student(1, "s1")
        d = Discipline(1, "d1", "p1")
        d1s1 = Student_Discipline(3, s.get_student_id() ,d.get_discipline_id(),-5)
        try:
            sv.validate(s)
            dv.validate(d)
            sdv.validate(d1s1)
            assert False
        except ValidatorError:
            assert True
            
def suite():
    suite = unittest.TestSuite()
    suite.addTests(unittest.TestLoader().loadTestsFromTestCase(StudentValidatorTestCase))
    suite.addTests(unittest.TestLoader().loadTestsFromTestCase(DisciplineValidatorTestCase))
    suite.addTests(unittest.TestLoader().loadTestsFromTestCase(StudentDisciplineValidatorTestCase))
    return suite
            
        
