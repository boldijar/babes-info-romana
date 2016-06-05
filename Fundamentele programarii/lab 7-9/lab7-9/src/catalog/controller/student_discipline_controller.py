'''
Created on Nov 25, 2014

@author: Iulian
'''
from catalog.domain.entities import Student_Discipline
from catalog.domain.validators import ValidatorError, StoreError
from catalog.domain.dto import StudentDisciplineAssembler
from _operator import itemgetter

class StudentDisciplineController(object):
    def __init__(self, student_repo, discipline_repo, student_discipline_repo):
        self.__student_repo = student_repo
        self.__discipline_repo = discipline_repo
        self.__student_discipline_repo = student_discipline_repo
    
    def find(self, Id):
        try:
            return self.__student_discipline_repo.find_by_id(Id)
        except ValidatorError as ve:
            raise StoreError(ex=ve)

             
    def assign_grades_student(self, student_discipline_id, student_id, discipline_id, grade):
        st_di = Student_Discipline(student_discipline_id, student_id, discipline_id, grade)
        try:
            self.__student_discipline_repo.add_item(st_di)
            return st_di
        except ValidatorError as ve:
            raise StoreError(ex=ve)
    
    
    def get_students_with_disciplines_and_grades(self):
        st_di = self.__student_discipline_repo.get_all()
        l=[]
        for i in st_di:
            try:
                sdi = i.get_student_discipline_id()
                st = i.get_student_id()
                di = i.get_discipline_id()
                grade = i.get_grade()
                s = self.__student_repo.find_by_id(st)
                d = self.__discipline_repo.find_by_id(di)
                
                dto = StudentDisciplineAssembler.create_student_discipline_dto(sdi, s, d, grade)
                l.append(dto)
            except ValidatorError as ve:
                raise StoreError(ex=ve)
        return l
    
    def student_grade_change(self, Id, new_grade):
        student_discipline = self.__student_discipline_repo.find_by_id(Id)
        
        student_id = student_discipline.get_student_id()
        discipline_id = student_discipline.get_discipline_id()
        
        st_di = Student_Discipline(Id, student_id, discipline_id, new_grade)
        
        try:
            self.__student_discipline_repo.update(st_di)
            return st_di
        except ValidatorError as ve:
            raise StoreError(ex=ve)
    
    def sort_by_name(self, l):
        for s in range(0, len(l)):
            for d in range(s, len(l)):
                if l[s].student_name > l[d].student_name:
                    aux = l[s]
                    l[s] = l[d]
                    l[d] = aux   
     
    def sort_by_grade(self, l):
        for s in range(0, len(l)):
            for d in range(s, len(l)):
                if l[s].grade < l[d].grade:
                    aux = l[s]
                    l[s] = l[d]
                    l[d] = aux   
    
    def students_and_grades_at_one_discipline_sorted(self, discipline_id):
        sd = self.__student_discipline_repo.get_all()
        list_items_with_one_discipline = []
        list_items_with_one_disciplineDTO = []
        for item in sd:
            if item.get_discipline_id() == discipline_id:
                list_items_with_one_discipline.append(item)
        
        for i in list_items_with_one_discipline:
            try:
                sdi = i.get_student_discipline_id()
                st = i.get_student_id()
                di = i.get_discipline_id()
                grade = i.get_grade()
                s = self.__student_repo.find_by_id(st)
                d = self.__discipline_repo.find_by_id(di)
                
                dto = StudentDisciplineAssembler.create_student_discipline_dto(sdi, s, d, grade)
                list_items_with_one_disciplineDTO.append(dto)
            except ValidatorError as ve:
                raise StoreError(ex=ve)
        self.sort_by_name(list_items_with_one_disciplineDTO)
        return list_items_with_one_disciplineDTO
        
    def students_and_grades_at_one_discipline_sorted_by_grade(self, discipline_id):
        sd = self.__student_discipline_repo.get_all()
        list_items_with_one_discipline = []
        list_items_with_one_disciplineDTO = []
        for item in sd:
            if item.get_discipline_id() == discipline_id:
                list_items_with_one_discipline.append(item)
        
        for i in list_items_with_one_discipline:
            try:
                sdi = i.get_student_discipline_id()
                st = i.get_student_id()
                di = i.get_discipline_id()
                grade = i.get_grade()
                s = self.__student_repo.find_by_id(st)
                d = self.__discipline_repo.find_by_id(di)
                
                dto = StudentDisciplineAssembler.create_student_discipline_dto(sdi, s, d, grade)
                list_items_with_one_disciplineDTO.append(dto)
            except ValidatorError as ve:
                raise StoreError(ex=ve)
        self.sort_by_grade(list_items_with_one_disciplineDTO)
        return list_items_with_one_disciplineDTO
    
    def get_first_20_percent(self,l):
        aux = []
        x = len(l)//5
        for s in range(0, x):
            try:
                aux.append(l[s])
            except ValidatorError as ve:
                raise StoreError(ex=ve)
        return aux
    
    def average_grade_at_all_disciplines(self):
        sd = self.__student_discipline_repo.get_all() #sd - lista studentilor cu note asignate la diferite discipline
        studentsId = []
        studentsIdDisc = []
        for i in sd:
            idC = i.get_student_id() #id student curent
            p=0
            for j in studentsId:
                if j == idC: #daca am gasit in lista rez acelasi id
                    p=1
                
            if p==0:
                studentsId.append(idC)
        for i in studentsId:
            suma = 0
            nr = 0
            for j in sd:
                if i == j.get_student_id():
                    suma = suma + j.get_grade()
                    nr = nr + 1
            studentsIdDisc.append((i,suma/nr))
        
        sorted(studentsIdDisc, key = itemgetter(1), reverse = True)    
        return studentsIdDisc