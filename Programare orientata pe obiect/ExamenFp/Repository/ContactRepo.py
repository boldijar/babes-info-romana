'''
Created on Jan 25, 2013

@author: Vlad Mihai
'''
from Domain.Agenda import *
class ContactRepo:
    def __init__(self,fileN):
        """
        creates an ContactRepo object which includes a list of 
        contacts and the name of the file in which the data are saved
        """
        self._fileN = fileN
        self._list = []
        self.ReadFile(self.getFile())
    def getFile(self):
        """
        returns the path(file name)
        """
        return self._fileN
    def getList(self):
        """
        returns the list of contacts
        """
        return self._list
    def addContact(self,id,name,phone,group):
        """
        appends(adds at the end of the list ) a new 
        Contact object and then reWrites the list in the database file
        """
        c = Contact(id,name,phone,group)
        self.getList().append(c)
        self.WriteInFile(self.getFile())
    def ReadFile(self,fileN):
        """
        Reads all the contacts from a file and then put the in the Repository list
        fileN = the path to the file
        """
        f = open(fileN,"r")
        line = f.readline().strip()
        l = line.split()
        while line != "":
            c = Contact(l[0], l[1],l[2],l[3])
            self.getList().append(c)
            line = f.readline().strip()
            l = line.split()
    def WriteInFile(self,fileN):
        """
        Writes in file the list of contacts. 
        fileN = The path to the file
        """
        f = open(fileN,"w")
        for i in self.getList():
            f.write(str(i) + "\n")
        f.close()
    def FindNumberByName(self,name):
        """
        Searches in the Contact list the name of the 
        contact and when it finds it returns the contact
        name = the name of the contact
        """
        for i in self.getList():
            if(i.getName() == name):
                return i
    def FindByGroup(self,group):
        """
        Searches in the Contact list the group of the 
        contact and when it finds it appends the contact to a list
        at the end it returns the list
        group = the group that is searched
        """
        l = []
        for i in self.getList():
            if(i.getGroup() == group):
                l.append(i)
        return l
    def ExportContact(self,fileN, group):
        """
        first is searches all the contacts from a group and put them in a list
        then it writes the list in a CSV file
        fileN = the name of the file in which it should write
        group = the group that is searched
        """
        l = self.FindByGroup(group)
        f = open(fileN,"w")
        for i in l:
            f.write(str(i.getName()) + "," + str(i.getPhone()) + "\n")
def testRepo():
    l = ContactRepo("test.txt")
    l.addContact("3","Marius","5555","Other")
    assert l.getList()[3].getName() == "Marius"
    assert l.FindNumberByName("Paul").getGroup() == "Friends"
    assert l.FindByGroup("Friends")[0].getName() == "Paul"
testRepo()
        