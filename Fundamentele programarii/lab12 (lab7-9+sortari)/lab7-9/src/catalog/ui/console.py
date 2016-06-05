'''
Created on Nov 11, 2014

@author: Iulian
'''
from catalog.domain.validators import StoreError
from catalog.ui.recursive import print_students

class Console(object):
    def __init__(self, student_controller, discipline_controller, student_discipline_controller):
        self.__student_controller = student_controller
        self.__discipline_controller = discipline_controller
        self.__student_discipline_controller = student_discipline_controller
        
    def add_students(self):
        try:
            Id = int(input("Introduceti id-ul: "))
            name = input("Introduceti numele: ")
        
            self.__student_controller.add_student(Id, name)
        except StoreError as se:
            print(se)
            #traceback.print_exc()
    def add_disciplines(self):
        try:
            Id = int(input("Introduce-ti id-ul: "))
            name = input("Introduceti numele disciplinei: ")
            prof = input("Introduceti numele profesorului: ")
            
            self.__discipline_controller.add_discipline(Id, name, prof)
        except StoreError as se:
            print(se)
            
    def print_students(self):
        l = self.__student_controller.print_students()
        print_students(l, 0)
    
    def print_disciplines(self):
        l = self.__discipline_controller.print_disciplines()
        for e in l:
            print(e)
    
    def delete_student(self):
        try:
            Id = int(input("Introduceti id-ul: "))
            self.__student_controller.delete_student(Id)
        except StoreError as se:
            print(se)
    
    def assign_grades_student(self):
        try:
            student_discipline_id = int(input("Id student si disciplina in catalog: "))
            student_id = int(input("Id student: "))
            discipline_id = int(input("Id disciplina: "))
            grade = int(input("Nota: "))
            self.__student_discipline_controller.assign_grades_student(student_discipline_id, student_id, discipline_id, grade)
        except StoreError as se:
            print(se)
    
    def student_grade_change(self):
        try:
            student_discipline_id = int(input("Id student in catalog: "))
            student_discipline = self.__student_discipline_controller.find(student_discipline_id)
            
            print("Id student: " , student_discipline.get_student_id())
            print("Id disciplina: ", student_discipline.get_discipline_id())
            grade = int(input("Dati noua nota: "))
            self.__student_discipline_controller.student_grade_change(student_discipline_id, grade)
        except StoreError as se:
            print(se)
    
    def print_students_with_disciplines_and_grades(self):
        l = self.__student_discipline_controller.get_students_with_disciplines_and_grades()
        for e in l:
            print(e)
            
    def delete_discipline(self):
        try:
            Id = int(input("Introduceti id-ul: "))
            self.__discipline_controller.delete_discipline(Id)
        except StoreError as se:
            print(se)
            
    def discipline_change(self):
        try:
            discipline_id = int(input("Id disciplina: "))
            discipline_name = input("Nume disciplina: ")
            prof_name = input("Nume profesor: ")
            self.__discipline_controller.discipline_change(discipline_id, discipline_name, prof_name)
        except StoreError as se:
            print(se)
    
    def print_students_and_grades_at_one_discipline_sorted(self):
        discipline_id = int(input("Id disciplina: "))
        l = self.__student_discipline_controller.students_and_grades_at_one_discipline_sorted(discipline_id)
        for e in l:
            print(e)
    
    def print_students_and_grades_at_one_discipline_sorted_by_grade(self):
        discipline_id = int(input("Id disciplina: "))
        l = self.__student_discipline_controller.students_and_grades_at_one_discipline_sorted_by_grade(discipline_id)
        for e in l:
            print(e)
            
    def find_student(self):
        try:
            Id = int(input("Id student"))
            print(self.__student_controller.find_student(Id))
        except StoreError as se:
            print(se)
    '''
    def print_students_with_grades(self):
        l = self.__student_discipline_controller.print_students_with_grades()
        for e in l:
            print(e.get_student(), "  " , e.get_discipline().get_discipline_name() , " nota: " , e.get_grade() )
    '''
    
    def print_first_20_percent(self):
        l = self.__student_discipline_controller.average_grade_at_all_disciplines()
        rez = self.__student_discipline_controller.get_first_20_percent(l)
        for s in rez:
            print(self.__student_controller.find_student(s[0]), s[1])
              
    def print_all_options(self):
        print("        1. Afisare studenti \n\
        2. Adauga student \n\
        3. Afisare discipline \n\
        4. Adauga disciplina \n\
        5. Stergerea unui student cu id-ul dat \n\
        6. Asignare nota unui student la o disciplina \n\
        7. Modificarea notei unui student la o disciplina \n\
        8. Stergerea unei discipline cu id-ul dat \n\
        9. Modificarea unei discipline \n\
        10. Cautarea unui student \n\
        11. Afisarea studentilor cu note asignate \n\
        12. Afisarea studentilor si a notelor lor la o disciplina data, ordonati alfabetic dupa nume \n\
        13. Afisarea studentilor si a notelor lor la o disciplina data, ordonati alfabetic dupa nota \n\
        14. Afișarea primilor 20% din studenți ordonați după media notelor la toate disciplinele")

        
    def run(self):
        while True:
            self.print_all_options()
            options = {1:self.print_students, 2: self.add_students, 3:self.print_disciplines, 4:self.add_disciplines,
                       5:self.delete_student, 6:self.assign_grades_student, 7:self.student_grade_change,
                       8:self.delete_discipline, 9:self.discipline_change, 10:self.find_student, 
                       11:self.print_students_with_disciplines_and_grades,
                       12:self.print_students_and_grades_at_one_discipline_sorted,
                       13:self.print_students_and_grades_at_one_discipline_sorted_by_grade,
                       14:self.print_first_20_percent}
            try:
                op = int(input("Dati optiunea: "))
            except ValueError:
                print("Optiune gresita")
                return
            options[op]()