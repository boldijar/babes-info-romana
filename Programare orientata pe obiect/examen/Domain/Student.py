'''
Created on Jan 23, 2013

@author: Vlad Mihai
'''
class Student:
    def __init__(self,id,name):
        self._id = id
        self._name = name
        """
        This function creates a student object 
            which is defined by 2 values: id and name.
        id - string - is unique
        name- string - the name of the student 
        """
    def getId(self):
        return self._id
    def getName(self):
        return self._name
    def __str__(self):
        return str(self._id) + " " + str(self._name)
    