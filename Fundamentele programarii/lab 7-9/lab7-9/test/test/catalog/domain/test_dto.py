'''
Created on Dec 2, 2014

@author: Iulian
'''

import unittest

from catalog.domain.dto import StudentDisciplineDTO

class StudentDisciplineDTOTestCase(unittest.TestCase):
    def test_create(self):
        sd = StudentDisciplineDTO(1, "s1", "d1", 3)
        assert sd.Id == 1
        assert sd.student_name =="s1"
        assert sd.discipline_name == "d1"
        assert sd.grade == 3
    
def suite():
    suite = unittest.TestSuite()
    suite.addTests(unittest.TestLoader().loadTestsFromTestCase(StudentDisciplineDTOTestCase))
    return suite

