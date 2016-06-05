'''
Created on Dec 2, 2014

@author: Iulian
'''

'''

@author: radu
'''
from catalog.domain.entities import Student_Discipline, Student, Discipline
from catalog.repository.repository import Repository, RepositoryError


class StudentFileRepository(Repository):

    def __init__(self, validator, file_name):
        Repository.__init__(self, validator)
        self.__file_name = file_name
        self.__load_students()
        
    def save(self, item):
        self.add_item(item)
        self.__save_student(item)

          
    def __load_students(self):
        try:
            with open(self.__file_name) as f:
                for line in f:
                    try:
                        arr = line.split(",")
                        p = Student(int(arr[0]), arr[1])
                        self.add_item(p)
                    except Exception as ex:
                        raise RepositoryError("Corrupted file", ex)
        except Exception as ex:
            raise RepositoryError("Error opening file " + self.__file_name, ex)
                
    def __save_student(self, Student):
        #TODO: handle exceptions
        try:
            with open(self.__file_name, "a") as f:
                s = str(Student.Id) + "," + Student.name + "\n"
                f.write(s)
        except Exception as ex:
            raise RepositoryError(ex)
                
class DisciplineFileRepository(Repository):
    def __init__(self, validator, file_name):
        Repository.__init__(self, validator)
        self.__file_name = file_name
        self.__load_disciplines()
        
    def save(self, item):
        self.add_item(item)
        self.__save_discipline(item)

          
    def __load_disciplines(self):
        try:
            with open(self.__file_name) as f:
                for line in f:
                    try:
                        arr = line.split(",")
                        p = Discipline(int(arr[0]), arr[1], arr[2])
                        self.add_item(p)
                    except Exception as ex:
                        raise RepositoryError("Corrupted file", ex)
        except Exception as ex:
            raise RepositoryError("Error opening file " + self.__file_name, ex)
                
    def __save_discipline (self, Discipline):
        #TODO: handle exceptions
        try:
            with open(self.__file_name, "a") as f:
                s = str(Discipline.Id) + "," + Discipline.Discipline_name + "," + Discipline.Discipline_prof + "\n"
                f.write(s)
        except Exception as ex:
            raise RepositoryError(ex)


class StudentDisciplineFileRepository(Repository):
    def __init__(self, validator, file_name):
        Repository.__init__(self, validator)
        self.__file_name = file_name
        self.__load_students_disciplines()
        
    def save(self, item):
        self.add_item(item)
        self.__save_student_discipline(item)

          
    def __load_students_disciplines(self):
        try:
            with open(self.__file_name) as f:
                for line in f:
                    try:
                        arr = line.split(",")
                        p = Student_Discipline(int(arr[0]), int(arr[1]), int(arr[2]), int(arr[3]) )
                        self.add_item(p)
                    except Exception as ex:
                        raise RepositoryError("Corrupted file", ex)
        except Exception as ex:
            raise RepositoryError("Error opening file " + self.__file_name, ex)
                
    def __save_student_discipline (self, Student_Discipline):
        #TODO: handle exceptions
        try:
            with open(self.__file_name, "a") as f:
                s = str(Student_Discipline.Id) + "," + str(Student_Discipline.student_id) + "," + str(Student_Discipline.discipline_id) + "," + str(Student_Discipline.grade) + "\n"
                f.write(s)
        except Exception as ex:
            raise RepositoryError(ex)
    
    

    
