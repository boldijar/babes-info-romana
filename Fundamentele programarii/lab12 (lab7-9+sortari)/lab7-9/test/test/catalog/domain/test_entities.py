'''
Created on Nov 11, 2014

@author: Iulian
'''
import unittest

from catalog.domain.entities import Student, Discipline, Student_Discipline

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

class Student_DisciplineTestCase(unittest.TestCase):
    def test_create(self):
        s1d1 = Student_Discipline(2, 1, 3, 5)
        assert s1d1.get_student_discipline_id() == 2
        assert s1d1.get_student_id() == 1
        assert( s1d1.get_discipline_id() == 3)
        assert s1d1.get_grade() == 5
    
def suite():
    suite = unittest.TestSuite()
    suite.addTests(unittest.TestLoader().loadTestsFromTestCase(StudentTestCase))
    suite.addTests(unittest.TestLoader().loadTestsFromTestCase(DisciplineTestCase))
    suite.addTests(unittest.TestLoader().loadTestsFromTestCase(Student_DisciplineTestCase))
    return suite