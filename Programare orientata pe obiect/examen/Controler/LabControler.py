'''
Created on Jan 24, 2013

@author: Vlad Mihai
'''
from Repository.LabRepo import *
from Repository.StudentRepo import *
from Controler.Validator import *
from Domain.Lab import *
from Domain.Student import *
class Controler:
    def __init__(self, LabRepo, StudentRepo,validator):
        self._labRep = LabRepo
        self._studRep = StudentRepo
        self._validator = validator
    def getLab(self):
        return self._labRep
    def getStud(self):
        return self._studRep
    def getValidator(self):
        return self._validator
    def addLab(self,idStudent,NrLab,NrProb):
        if(self.getValidator().ValidateLab(idStudent,NrLab)) == False:
            return "Error"
        self.getLab().AssignLabStud(idStudent, NrLab, NrProb)
           
            
    def SearchStudById(self, studID):
        s = self.getStud().FindStudentbyID(studID)
        return s
    def GetAllStundentLab(self,IdStudent):
        la = self.getLab().SearchbyStudent(IdStudent)
        return la
    def ViewAllStudents(self):
        s = self.getStud().showAll()
        return s
    def GetAllByLab(self,LabNr):
        sl = []
        l = self.getLab().SearchbyLab(LabNr)
        for i in l:
            s = self.getStud().FindStudentbyID(i.getStudID())
            sl.append(s.getName())
        return sl