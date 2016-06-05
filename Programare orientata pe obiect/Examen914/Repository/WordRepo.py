'''
Created on Jan 24, 2013

@author: Vlad Mihai
'''
from Domain.Word import *
class WordRepo:
    def __init__(self,fileN):
        self._fileN = fileN
        self._list = []
        self.ReadFile(self.getFileN())
    def getFileN(self):
        return self._fileN
    def getList(self):
        return self._list
    def ReadFile(self, fileN):
        f = open(fileN, "r")
        line = f.readline().strip()
        l = line.split()
        end = False
        while end != True:
            w = Word(l[0],l[1],l[2])
            self.getList().append(w)
            line = f.readline().strip()
            l = line.split()
            if(line == ""):
                end = True
        f.close()
    def AddWord(self,id,lang,wd):
        w = Word(id,lang,wd)
        self.getList().append(w)
        self.WriteInFile(self.getFileN())
    def WriteInFile(self,fileN):
        f = open(fileN,"w")
        for i in self.getList():
            f.write(str(i) + "\n")
        f.close()
    def FindWord(self,lang,word):
        for i in self.getList():
            if(i.getLanguage() == lang):
                if(i.getWord() == word):
                    return True
        return False
    def SpellText(self,lang,text):
        l = text.split()
        st = []
        for i in l:
            if(self.FindWord(lang,i)):
                st.append(i)
        return st
    def CheckText(self,intext,lang,outtext):
        f = open(intext, "r")
        line = f.readline().strip()
        l = line.split()
        li = []
        end = False
        while end != True:
            for i in l:
                li.append(i)
            line = f.readline().strip()
            l = line.split()
            if(line == ""):
                end = True
        f2 = open(outtext,"w")
        for i in li:
                if(self.FindWord(lang,i) == False):
                    if(len(i) > 2):
                        f2.write("{" + str(i) + "} ")
                    else:
                        f2.write(str(i) + " ")
                else:
                    f2.write(str(i)+ " ")
        f2.close()
                
            