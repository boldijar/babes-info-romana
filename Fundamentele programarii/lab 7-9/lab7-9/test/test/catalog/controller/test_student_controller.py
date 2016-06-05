'''
Created on Nov 11, 2014

@author: Iulian
'''
import unittest
from catalog.controller.student_controller import StudentController
from catalog.repository.repository import Repository
from catalog.domain.entities import Student
from catalog.domain.validators import StudentValidator

class StudentControllerTestCase(unittest.TestCase):
    def setUp(self):
        self.__repo = Repository(StudentValidator())
        s1 = Student(1, "s1")
        s2 = Student(2, "s2")
        s3 = Student(3, "s3")
        self.__repo.add_item(s1)
        self.__repo.add_item(s2)
        self.__repo.add_item(s3)
        self.__ctrl = StudentController(self.__repo)
        
    def test_add_student(self):
        self.__ctrl.add_student(4, "s4")
        assert(self.__repo.size() == 4)
        
    def test_get_all(self):
        l = self.__ctrl.get_all()
        assert(len(l) == 3)
    
    def test_delete_student(self):
        self.__ctrl.delete_student(3)
        assert self.__repo.size() == 2
    
    def test_find_student(self):
        s = self.__ctrl.find_student(2)
        assert s.Id == 2
        assert s.name == "s2"
        
        s = self.__ctrl.find_student(1)
        assert s.Id == 1
        assert s.name == "s1"
        
def suite():
    suite = unittest.TestSuite()
    suite.addTests(unittest.TestLoader().loadTestsFromTestCase(StudentControllerTestCase))
    return suite
        