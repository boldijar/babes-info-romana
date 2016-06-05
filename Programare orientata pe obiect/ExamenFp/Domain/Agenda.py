'''
Created on Jan 25, 2013

@author: Vlad Mihai
'''
class Contact:
    def __init__ (self,id, name,phonenr,group):
        """
        Creates a Contact object
        id = the id of the contact
        name = the name of the contact
        phonenr  = the phone number of the contact
        group = the group 
        """
        self._id = id
        self._name = name
        self._phone = phonenr
        self._group = group
    def getId(self):
        """
        returns the ID
        """
        return self._id
    def getName(self):
        """
        returns the name
        """
        return self._name
    def getPhone(self):
        """
        returns the phone number
        """
        return self._phone
    def getGroup(self):
        """
        returns the group
        """
        return self._group
    def __str__(self):
        """
        returns a string that includes all the information of a contact separated by one space
        """
        return str(self.getId()) + " " + str(self.getName()) + " " + str(self.getPhone())+ " " + str(self.getGroup())
    
def testContact():
    c = Contact("1","Claudiu","6666","Friends")
    assert c.getId() == "1"
    assert c.getName() == "Claudiu"
    assert c.getPhone() == "6666"
    assert c.getGroup() == "Friends"
testContact()