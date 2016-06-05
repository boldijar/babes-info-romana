'''
Created on Jan 24, 2013

@author: Vlad Mihai
'''
from Repository.LabRepo import *
from Repository.StudentRepo import *
from Domain.Lab import *
from Controler.LabError import *
class Validator:
    def __init__(self,studRep,labRep):
        self._studRep = studRep
        self._labRep = labRep
    def getStud(self):
        return self._studRep
    def getLab(self):
        return self._labRep
    def ValidateLab(self,studID,LabNr):
        for i in self.getLab().SearchbyStudent(studID):
            if i.getLabNR() == LabNr:
                return False
            