'''
Created on Nov 19, 2014

@author: Iulian
'''
import unittest
from catalog.domain.validators import StudentValidator, ValidatorError,\
    DisciplineValidator
from catalog.domain.entities import Student, Discipline

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
          

def suite():
    suite = unittest.TestSuite()
    suite.addTests(unittest.TestLoader().loadTestsFromTestCase(StudentValidatorTestCase))
    suite.addTests(unittest.TestLoader().loadTestsFromTestCase(DisciplineValidatorTestCase))
    return suite
            
        
