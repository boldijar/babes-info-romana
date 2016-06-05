'''
Created on Jan 24, 2013

@author: Vlad Mihai
'''
from Repository.WordRepo import *
from Domain.Validator import *

class Controller:
    def __init__(self,repo, validator):
        self._repo = repo
        self._valid = validator
    def getRepo(self):
        return self._repo
    def getValid(self):
        return self._valid
    def addWord(self,id, lang,word):
        if(self.getValid().CheckWord(word,lang) == False):
            return "Error"
        self.getRepo().AddWord(id,lang,word)
    def SpellText(self,lang,t):
        st = self.getRepo().SpellText(lang,t)
        return st
    def CheckFile(self, inFile, lang, outFile):
        self.getRepo().CheckText(inFile,lang,outFile)
            