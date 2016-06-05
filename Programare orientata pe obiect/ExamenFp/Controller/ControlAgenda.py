'''
Created on Jan 25, 2013

@author: Vlad Mihai
'''
from Repository.ContactRepo import *
from Domain.Validator import *

class Controller:
    def __init__(self,repo,valid):
        """
        Creates a Controller object
        repo - Repository
        valid = Validator
        """
        self._repo = repo
        self._valid = valid
    def getRepo(self):
        """
        Returns the Repository
        """
        return self._repo
    def getValid(self):
        """
        Returns the Validator
        """
        return self._valid
    def addContact(self,id,name,phone,group):
        """
        checks if the data of a new contact are valid and if they are valid adds it to 
        the repository else it returns an Error message that will be printed in the UI
        """
        if(self.getValid().CheckName(name) == True ):
            if(self.getValid().CheckGroup(group) == True):
                if(self.getValid().CheckPhone(phone) == True):
                    self.getRepo().addContact(id,name,phone,group)
                else:
                    return "The Phone Number is Wrong or already in the Agenda"
            else:
                return "The group is not one of Friends, Family, Others"
        else:
            return "The name can't be empty"
        return ""
    def FindNumber(self,name):
        """
        returns a Contact that has a certain name
        """
        s = self.getRepo().FindNumberByName(name)
        return s
    def FindByGroup(self,group):
        """
        Returns Error if The group is not valid
        or returns a list of Contacts that are in the same group
        """
        if(self.getValid().CheckGroup(group) == False):
            return "Error"
        return self.getRepo().FindByGroup(group)
    def ExportContact(self,group):
        """
        Returns Error if the group is not valid
        or writes in "CSV.txt" file the contacts(only the names and the phone numbers) from that group separated by ","
        """
        if(self.getValid().CheckGroup(group) == False):
            return "Error"
        self.getRepo().ExportContact("CSV.txt",group)
def testCont():
    r = ContactRepo("test.txt")
    v = Validator(r)
    c = Controller(r,v)
    c.addContact("3","Marius","5555","Other")
    assert c.getRepo().getList()[3].getName() == "Marius"
    assert c.FindNumber("Paul").getGroup() == "Friends"
    assert c.FindByGroup("Friends")[0].getName() == "Paul"
testCont()