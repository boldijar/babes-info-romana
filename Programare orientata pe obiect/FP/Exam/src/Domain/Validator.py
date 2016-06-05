from Domain.Contact import *

class Validator:
    def __init__(self):
        pass
    def validate(self,contact):
        """
            Verify if a contact is valid
            A contact can be valid if the phone number is not empty, the name is not on the list and the group name is correct
        """
        if contact.getPhoneNr()=='':
            return False
        if contact.getGroup()<>'Family' and contact.getGroup()<>'Friends' and contact.getGroup()<>'Others':
            return False
        try:
            x=int(contact.getPhoneNr())
        except ValueError:
            return False

        return True

def testValidator():
    """
        Test function for the Validator
    """
    v=Validator()
    assert v.validate(Contact(1,'Name','0987654321','Family'))==True
    assert v.validate(Contact(1,'Name','','Family'))==False
    assert v.validate(Contact(1,'Name','0987654321','vvvfd'))==False
    assert v.validate(Contact(1,'Name','abc','Family'))==False
testValidator()

