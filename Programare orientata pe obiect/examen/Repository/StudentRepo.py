'''
Created on Jan 23, 2013

@author: Vlad Mihai
'''
from Domain.Student import *
class StudentRepo:
    def __init__(self,fileN):
        self._fileN = fileN
    def getFileN(self):
        return self._fileN
    def FindStudentbyID(self,stid):
        f = open(self.getFileN(),"r")
        line = f.readline().strip()
        l = line.split()
        end = False
        while end != True:
            s = Student(int(l[0]),l[1])
            if(s.getId() == stid):
                return s 
            line = f.readline().strip()
            l = line.split()
            if(line == ["End"]):
                end = True
    def showAll(self):
        li = []
        f = open(self.getFileN(),"r")
        line = f.readline().strip()
        l = line.split()
        end = False
        while end != True:
            s = Student(int(l[0]),l[1])
            li.append(s)
            line = f.readline().strip()
            l = line.split()
            if(line == "End"):
                end = True
        return li 
def testRepo():
    s = StudentRepo("teststudent.txt")
    stud = s.FindStudentbyID(6)
    assert stud.getName() == "Ovidiu"
    l = s.showAll()
    assert len(l) == 6
testRepo()
    