class Contact:
    def __init__(self,id,name,phoneNr,group):
        """
            Initialise the contact
            id is the contact's id given by the user
            name is the contact's name
            phoneNr is the contact's phone number
            group is the name of the group where the contact belongs
        """
        self.__ID=id
        self.__Name=name
        self.__PhoneNr=phoneNr
        self.__Group=group
    def getID(self):
        """
            Return the ID of the contact
        """
        return self.__ID
    def getName(self):
        """
            Return the name of the contact
        """
        return self.__Name
    def getPhoneNr(self):
        """
            Return the phone number of the contact
        """
        return self.__PhoneNr
    def getGroup(self):
        """
            Retrun the name of the group where the contact belongs
        """
        return self.__Group

def testContact():
    """
        Test function for the Contact class
    """
    c=Contact(1,'Name','012345','Group')
    assert c.getID()==1
    assert c.getName()=='Name'
    assert c.getPhoneNr()=='012345'
    assert c.getGroup()=='Group'

testContact()