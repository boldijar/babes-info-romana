'''
Created on Jan 23, 2013

@author: Vlad Mihai
'''
class Lab:
    def __init__(self,studID, labNR, probNR):
        self._studID = studID
        self._labNR = labNR
        self._probNR = probNR
        """
        This function creates a Laboratory object which is defined
            by the student ID, the laboratory number and the problem number
            (that has been assigned for that lab for a student)
            studID - integer - student ID
            labNR - integer - the Number of the LAB
            probNR - integer - The number of the problem
        """ 
    def getStudID(self):
        return self._studID
    def getLabNR(self):
        return self._labNR
    def getProbNR(self):
        return self._probNR
    def __str__(self):
        return str(self.getStudID()) + " " + str(self.getLabNR()) + " " + str(self.getProbNR())
def test():
    l = Lab(1,2,"3")
    print l 
test()