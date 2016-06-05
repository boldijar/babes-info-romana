'''
Created on Jan 24, 2013

@author: Vlad Mihai
'''
from Repository.WordRepo import *
from Domain.Word import *

class Validator:
    def __init__(self,wordRepo):
        self._wdRepo = wordRepo
    def getWordRepo(self):
        return self._wdRepo
    def CheckWord(self,word, lang):
        if word == "":
            return False
        if(lang != "En" and lang != "Ro" and lang != "Fr" ):
            return False
        for i in self.getWordRepo().getList():
            if(i.getLanguage() == lang):
                if(i.getWord() == word):
                    return False
                
    
        