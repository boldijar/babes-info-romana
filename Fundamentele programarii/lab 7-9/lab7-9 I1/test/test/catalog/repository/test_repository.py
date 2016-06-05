'''
Created on Nov 11, 2014

@author: Iulian
'''

import unittest

from catalog.domain.entities import Student
from catalog.repository.repository import Repository
from catalog.domain.validators import StudentValidator

class RepositoryTestCase(unittest.TestCase):
    def setUp(self):
        self.__repo = Repository(StudentValidator())
        s1 = Student(1, "s1")
        s2 = Student(2, "s2")
        s3 = Student(3, "s3")
        self.__repo.save(s1)
        self.__repo.save(s2)
        self.__repo.save(s3)

    def test_size(self):
        assert(self.__repo.size() == 3)
    
    def test_save(self):
        s = Student(4, "s4")
        self.__repo.save(s)
        assert(self.__repo.size() == 4)
        
    def test_get_all(self):
        l = self.__repo.get_all()
        assert(len(l) == 3)
        
    def test_delete(self):
        self.__repo.delete(3)
        assert self.__repo.size() == 2
def suite():
    suite=unittest.TestSuite()
    suite.addTests(unittest.TestLoader().loadTestsFromTestCase(RepositoryTestCase))
    return suite
