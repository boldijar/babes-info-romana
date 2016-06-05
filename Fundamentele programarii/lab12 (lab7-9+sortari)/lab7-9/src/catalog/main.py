'''
Created on Nov 11, 2014

@author: Iulian
'''
from catalog.repository.file_repository import StudentFileRepository,\
    DisciplineFileRepository, StudentDisciplineFileRepository

"""
P1. Catalog studenți
Facultatea stochează informații despre:
•    studenți: <IDStudent>,<nume>
•    discipline: <idDisciplină>, <nume>, <profesor>
Creați o aplicație care permite:
•    gestionarea listei de studenți si listei de discipline.
•    adaugă, șterge, modifică, lista de studenți, listă de discipline
•    căutare student, căutarea de disciplină.
•    Asignare de note la un student și o disciplină
•    Creare de statistici: 
a.    lista de studenți și notele lor la o disciplină dată, ordonat: alfabetic după nume, după notă.
b.    Primi 20% din studenți ordonat după media notelor la toate disciplinele (nume și notă)

Funcționalități:
F1 – Afișarea studenților
F2 – Adăugarea unui nou student
F3 – Ștergerea unui student
F4 – Modificarea notei unui student la o disciplina
F5 – Căutarea unui student
F6 – Asignarea de note unui student la o disciplină
F7 – Afișarea studenților și a notelor lor la o disciplină dată, ordonați alfabetic după nume
F8 - Afișarea studenților și a notelor lor la o disciplină dată, ordonați după notă
F9 – Afișarea primilor 20% din studenți ordonați după media notelor la toate disciplinele (nume și notă)
F10 – Afișarea disciplinelor
F11 – Adăugarea unei discipline
F12 – Ștergerea unei discipline
F13 – Modificarea unei discipline
F14 – Căutarea unei discipline 
F15 – Afișarea studenților cu nota asignată

"""
#from catalog.repository.repository import Repository
from catalog.controller.student_controller import StudentController
from catalog.ui.console import Console
from catalog.domain.validators import StudentValidator, DisciplineValidator,\
    StudentDisciplineValidator
from catalog.controller.discipline_controller import DisciplineController
from catalog.controller.student_discipline_controller import StudentDisciplineController

class App(object):
    def main(self):
        
        #student_repo = Repository(StudentValidator())        
        student_repo = StudentFileRepository(StudentValidator(),"../../data/students") 
        sc = StudentController(student_repo)

        discipline_repo = DisciplineFileRepository(DisciplineValidator(), "../../data/disciplines")
        dc = DisciplineController(discipline_repo)
        
        student_discipline_repo = StudentDisciplineFileRepository(StudentDisciplineValidator(), "../../data/student_discipline")
        sdc = StudentDisciplineController(student_repo, discipline_repo, student_discipline_repo)
        
        cons = Console(sc, dc, sdc)
        cons.run()
        
if __name__ == '__main__':
    try:
        app = App()
        app.main()
    except Exception as ex:
        print("Exceptie in aplicatie: ", ex)
        