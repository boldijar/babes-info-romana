'''
Created on Nov 19, 2014

@author: Iulian
'''
import unittest
from catalog.repository.repository import Repository
from catalog.controller.discipline_controller import DisciplineController
from catalog.domain.entities import Discipline
from catalog.domain.validators import DisciplineValidator

class DisciplineControllerTestCase(unittest.TestCase):
    def setUp(self):
        self.__repo = Repository(DisciplineValidator())
        d1 = Discipline(1, "d1", "p1")
        d2 = Discipline(2, "d2", "p2")
        d3 = Discipline(3, "d3", "p3")
        self.__repo.add_item(d1)
        self.__repo.add_item(d2)
        self.__repo.add_item(d3)
        self.__ctrl = DisciplineController(self.__repo)
        
    def test_add_discipline(self):
        self.__ctrl.add_discipline(4, "d4", "p4")
        assert(self.__repo.size() == 4)
        
    def test_get_all(self):
        l = self.__ctrl.get_all()
        assert(len(l) == 3)
    
    def test_delete_discipline(self):
        self.__ctrl.delete_discipline(2)
        assert(self.__repo.size() == 2)
        
        self.__ctrl.delete_discipline(3)
        assert(self.__repo.size() == 1)
        
    def test_discipline_change(self):
        self.setUp()
        assert self.__repo.size() == 3
        d = self.__ctrl.discipline_change(1, "mate", "profmate")
        assert d.Discipline_name == "mate"
        assert d.Discipline_prof =="profmate"
        assert d.Id == 1
        
        
def suite():
    suite = unittest.TestSuite()
    suite.addTests(unittest.TestLoader().loadTestsFromTestCase(DisciplineControllerTestCase))
    return suite
        