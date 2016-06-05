'''
Created on Nov 11, 2014

@author: Iulian
'''
import unittest

from catalog.domain.entities import Student, Discipline

class StudentTestCase(unittest.TestCase):
    def test_create(self):
        s1 = Student(1, "S1")
        assert ( s1.get_student_id() == 1 )
        assert ( s1.get_student_name() == "S1" )
        assert ( s1.Id == 1)
        assert ( s1.name == "S1")

class DisciplineTestCase(unittest.TestCase):
    def test_create(self):
        d1 = Discipline(1, "d1", "p1")
        assert ( d1.get_discipline_id() == 1 )
        assert ( d1.get_discipline_name() == "d1" )
        assert ( d1.get_discipline_prof() == "p1")
        assert ( d1.Id == 1)
        assert ( d1.Discipline_name == "d1")
        assert ( d1.Discipline_prof == "p1")

    
def suite():
    suite = unittest.TestSuite()
    suite.addTests(unittest.TestLoader().loadTestsFromTestCase(StudentTestCase))
    suite.addTests(unittest.TestLoader().loadTestsFromTestCase(DisciplineTestCase))
    return suite