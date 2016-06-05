'''
Created on Jan 23, 2013

@author: Vlad Mihai
'''
from Domain.Lab import *
class LabRepo:
    def __init__(self,fileN):
        self._fileN = fileN
        self._l = []
        self.ReadFile()
    def getFileN(self):
        return self._fileN
    def getList(self):
        return self._l
    def WriteList(self):
        f = open(self.getFileN(),"w")
        for i in self.getList():
            f.write(str(i.getStudID())+"," +str(i.getLabNR())+"," + str(i.getProbNR())  + "\n")
        f.close()
    def ReadFile(self):
        f = open(self.getFileN(), "r")
        line = f.readline().strip()
        l = line.split(",")
        end = False
        while end != True:
            s = Lab(int(l[0]),int(l[1]),l[2])
            self.getList().append(s)
            line = f.readline().strip()
            l = line.split(",")
            if(line == ''):
                end = True
        f.close()
    def AssignLabStud(self,studId,labNR,probNR):
        laborator = Lab(studId,labNR,probNR)
        self.getList().append(laborator)
        self.WriteList()
    def SearchbyStudent(self,studentID):
        sl = []
        for i in self.getList():
            if int(i.getStudID()) == int(studentID):
                 sl.append(i)
        return sl
    def SearchbyLab(self,LabNr):
        sl = []
        for i in self.getList():
            if(int(i.getLabNR()) == int(LabNr)):
                sl.append(i)
        return sl
    def __len__(self):
        return len(self.getList())
def testLabRepo():
    l = LabRepo("testlabs.txt")
    #assert len(l) == 2
    l.AssignLabStud(3,5,1)
    #assert len(l) == 3
    l = l.SearchbyStudent(1)
    assert len(l) == 1
testLabRepo()
