'''
Created on Jan 25, 2013

@author: Vlad Mihai
'''
from Controller.ControlAgenda import *
from Domain.Agenda import *

class UI:
    def __init__(self,control):
        self._control = control
    def getControl(self):
        return self._control
    def Console(self):
        """
        Prints all the results and reads all the information from the keyboard
        """
        while True:
            print "Press 0 to exit"
            print "Press 1 to add a new contact"
            print "Press 2 to Find a number by name"
            print "Press 3 to Find contacts by group"
            print "Press 4 to Export Contacts"
            c = raw_input("Select Menu:")
            if( c == "0"):
                exit()
            elif(c == "1"):
                i = raw_input("Select an id")
                n = raw_input("Select name:")
                p = raw_input("Select phone number")
                g = raw_input("Select group")
                s = self.getControl().addContact(i,n,p,g)
                if(s != ""):
                    print s
            elif c == "2":
                n = raw_input("Select Name")
                s = self.getControl().FindNumber(n)
                if(s == None):
                    print "The number does not Exist"
                else:
                    print s.getPhone()
            elif c == "3":
                g = raw_input("Select the group:")
                s = self.getControl().FindByGroup(g)
                if(s == "Error"):
                    print "The group is not one of Friends, Family, Others"
                else:
                    if len(s) == 0:
                        print "The group is empty"
                    else:
                        for i in s:
                            print i
            elif( c == "4"):
                g = raw_input("Select Group:")
                s = self.getControl().ExportContact(g)
                if s == "Error":
                    print "The group is not one of Friends, Family, Others"
                