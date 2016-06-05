'''
Created on Jan 24, 2013

@author: Vlad Mihai
'''
class LabError(Exception):
    def __init__(self):
        raise ValueError( "You have assigned two problems for the same lab at the same student!!!!!!")
    def getErrors(self):
        return self._error