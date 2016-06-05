'''
Created on Jan 25, 2013

@author: Vlad Mihai
'''
from Repository.ContactRepo import *
from Domain.Agenda import *
class Validator:
    def __init__(self,repo):
        self._repo = repo
    def getRepo(self):
        return self._repo
    def CheckName(self,name):
        """
        checks if the name is not empty
        """
        if name == "":
            return False
        return True
    def CheckGroup(self,group):
        """
        checks if the group is valid
        """
        if(group == "Friends" or group == "Family" or group == "Others"):
            return True
        return False
    def CheckPhone(self,phone): 
        """
        checks if the phone number is not empty and contains only digits
        """
        if(phone == ""):
            return False
        l = ["0","1","2","3","4","5","6","7","8","9"]
        for i in phone:
            if(i not in l ):
                return False
        for i in self.getRepo().getList():
            if( i.getPhone() == phone):
                return False
        return True
def testValid():
    r = ContactRepo("test.txt")
    v = Validator(r)
    assert v.CheckName("") == False
    assert v.CheckGroup("Family") == True
    assert v.CheckPhone("888") == False
     
    
testValid()