'''
Created on Jan 23, 2013

@author: Maria
'''
from Domain.Word import Word
from Repository.WordsRepository import WordsRepository
from Domain.WordValidator import WordValidator

class SpellCheckerController:
    def __init__(self,wlist):
        self.__wlist=wlist
        
    def addWord(self,id,lang,word):
        val=WordValidator()
        try:
            val.wordempty(id, lang, word)
        except ValueError:
            return "empty fields"
        
        try:
            val.goodLanguage(lang)
        except ValueError:
            return "not existing language"
        
        try:
            val.existingword(self.__wlist, word, lang)
        except ValueError:
            return "word already exists"
        newWord=Word(id,lang,word)
        self.__wlist.add(newWord)
        return ""
        
    def getList(self):
        """
        this function returns all the elements of the wordlist from the repository to the ui
        """
        return self.__wlist.getAll()
    
    def check(self,lang,text):
        """
        this function checks each word from the text and returns only the ones 
        which are not in the dictionary
        """
        wordlist=[]
        field=text.split(" ")
        for i in range (0,len(field)):
            exists=self.__wlist.finds(lang,field[i])
            if (exists==False):
                wordlist.append(field[i])
        return wordlist
    
    def check2(self,inFName,lang,outFname):
        '''
        reads words from a file in a language
        checks if they exist in the dictionary
        for those who dont exist adds { }
        puts in the outFname file the resulted list
        '''
        wordlist=[]
        newlist=[]
        try:
            wordlist=self.__wlist.readWords(inFName)
        except IOError:
            return "can't open file"
        
        for i in range (0,len(wordlist)):
            exists=self.__wlist.finds(lang,wordlist[i])
            if exists==True:
                newlist.append(wordlist[i])
            else:
                newlist.append("{")
                newlist.append(wordlist[i])
                newlist.append("}")
                
        try:
            self.__wlist.writefile(outFname,newlist)
        except IOError:
            return "cannot open writing file"
        
        
        
                