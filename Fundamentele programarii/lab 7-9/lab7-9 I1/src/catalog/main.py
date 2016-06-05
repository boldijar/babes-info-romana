'''
Created on Nov 11, 2014

@author: Iulian
'''
from catalog.repository.repository import Repository
from catalog.controller.student_controller import StudentController
from catalog.ui.console import Console
from catalog.domain.validators import StudentValidator, DisciplineValidator
from catalog.controller.discipline_controller import DisciplineController


class App(object):
    def main(self):
        student_repo = Repository(StudentValidator())        
        sc = StudentController(student_repo)

        discipline_repo = Repository(DisciplineValidator())
        dc = DisciplineController(discipline_repo)
        
        
        cons = Console(sc, dc)
        cons.run()
        
if __name__ == '__main__':
    try:
        app = App()
        app.main()
    except Exception as ex:
        print("Exceptie in aplicatie: ", ex)
        