'''
Created on Jan 24, 2013

@author: Vlad Mihai
'''
from Controler.LabControler import *
from Domain.Lab import *
class UI:
    def __init__(self,controler):
        self._controler = controler
    def getControler(self):
        return self._controler
    def Console(self):
        while True:
            print "Welcome!"
            print "Press 1 if you want to view the list of students"
            print "Press 2 if you want to search a student by ID"
            print "Press 3 if you want to assign a laboratory to a student"
            print "Press 4 if you want to see all Lab assignments of a student"
            print "Press 0 if you want to exit"
            print "Press 5 if you want to show all the students with the lab assigment for a given lab number"
            s = raw_input("Select Menu:")
            if s == "0":
                exit()
            elif s == "1":
                l = self.getControler().ViewAllStudents()
                for i in l:
                    print i 
            elif s == "2":
                studId = raw_input("Select The Id of the student:")
                stud = self.getControler().SearchStudById(int(studId))
                print stud
            elif s == "3":
                studId= raw_input("Select The student Id:")
                labNr = raw_input("Select Lab Number:")
                probNr = raw_input("Select the Problem Number:")
                msg = self.getControler().addLab(int(studId),int(labNr),probNr)
                if(msg == "Error"):
                    print "You have assigned 2 labs for the same student!!!"
            elif s == "4":
                studId = raw_input("Select Studen Id:")
                l = self.getControler().GetAllStundentLab(int(studId))
                for i in l:
                    print i
            elif s == "5":
                labNr = raw_input("Select the Lab Number:")
                l = self.getControler().GetAllByLab(int(labNr))
                for i in l:
                    print i
                
                