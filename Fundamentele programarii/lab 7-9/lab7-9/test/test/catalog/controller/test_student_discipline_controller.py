'''
Created on Nov 26, 2014

@author: Iulian
'''
import unittest
from catalog.domain.validators import StudentDisciplineValidator,\
    DisciplineValidator, StudentValidator
from catalog.domain.entities import Student_Discipline, Discipline, Student
from catalog.repository.repository import Repository
    #StudentDisciplineRepository
from catalog.controller.discipline_controller import DisciplineController
from catalog.controller.student_controller import StudentController
from catalog.controller.student_discipline_controller import StudentDisciplineController

class StudentDisciplineControllerTestCase(unittest.TestCase):
    def setUp(self):
        self.__DisciplineRepo = Repository(DisciplineValidator())
        d1 = Discipline(1, "mate", "prof mate")
        d2 = Discipline(2, "info", "prof info")
        self.__DisciplineRepo.add_item(d1)
        self.__DisciplineRepo.add_item(d2)
        self.__Dctrl = DisciplineController(self.__DisciplineRepo)
        
        self.__StudentRepo = Repository(StudentValidator())
        s1 = Student(3, "Ion")
        s2 = Student(2, "Maria")
        s3 = Student(1, "Ionica")
        self.__StudentRepo.add_item(s1)
        self.__StudentRepo.add_item(s2)
        self.__StudentRepo.add_item(s3)
        self.__Sctrl = StudentController(self.__StudentRepo)
        
        self.__repo = Repository(StudentDisciplineValidator())
        sd = Student_Discipline(1, s1.get_student_id(), d1.get_discipline_id(), 6)
        self.__repo.add_item(sd)
        
        sd = Student_Discipline(2, s2.get_student_id(), d2.get_discipline_id(), 8)
        self.__repo.add_item(sd)
        
        sd = Student_Discipline(4, s3.get_student_id(), d2.get_discipline_id(), 3)
        self.__repo.add_item(sd)
        self.__ctrl = StudentDisciplineController(self.__StudentRepo, self.__DisciplineRepo, self.__repo)
    
    def test_assign_grades_student(self):
        s1d1 = self.__ctrl.assign_grades_student(1, 3, 2, 8)
        assert s1d1.get_student_discipline_id() == 1
        assert s1d1.get_discipline_id() == 2
        assert s1d1.get_student_id() == 3
        assert s1d1.get_grade() == 8
        
        s1d1 = self.__ctrl.assign_grades_student(3, 1, 1, 4)
        assert s1d1.get_discipline_id() == 1
        assert s1d1.get_student_id() == 1
        assert s1d1.get_grade() == 4
        
    def test_student_grade_change(self):
        s1d1 = self.__repo.find_by_id(1)
        s1d1 = self.__ctrl.student_grade_change(s1d1.get_student_discipline_id(), 10)
        assert s1d1.get_discipline_id() == 1
        assert s1d1.get_student_id() == 3
        assert s1d1.get_grade() == 10
        
    def test_get_students_with_disciplines_and_grades(self):
        l = self.__ctrl.get_students_with_disciplines_and_grades()
        assert len(l) == 3
    
    def test_students_and_grades_at_one_discipline_sorted(self):
        l = self.__ctrl.students_and_grades_at_one_discipline_sorted(2)
        assert len(l) == 2
        l = self.__ctrl.students_and_grades_at_one_discipline_sorted(1)
        assert len(l) == 1
    
    def test_students_and_grades_at_one_discipline_sorted_by_grade(self):
        l = self.__ctrl.students_and_grades_at_one_discipline_sorted_by_grade(2)
        assert len(l) == 2
        assert l[0].grade == 8
        assert l[1].grade == 3
              
def suite():
    suite = unittest.TestSuite()
    suite.addTests(unittest.TestLoader().loadTestsFromTestCase(StudentDisciplineControllerTestCase))
    return suite
