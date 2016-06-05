'''
Created on Jan 23, 2013

@author: Maria
'''
from Domain.Word import Word
class WordsRepository:
    def __init__(self,Dfile):
        
        self.__Dfile=Dfile
        self.__wordlist=[]
        self.loadD()
        
    def add(self,word):
        """precondition: Word is an object with 3 properties
        the Word is added in the wordlist at the end of the list
        """
        self.__wordlist.append(word)
    
    def getAll(self):
        '''
        precondition:none
        postcondition: returns all the elements of  the wordlist
        '''
        return self.__wordlist
    
    def loadD(self):
        '''
        function responsable with the loading of words from a file into the wordlist
        
        '''
        try:
            fileObj=open(self.__Dfile,"r")
        except IOError:
            return "can't open"
        line=fileObj.readline().strip()
        while line !="":
            field=line.split(" ")
            newWord=Word(field[0],field[1],field[2])
            self.__wordlist.append(newWord)
            line=fileObj.readline().strip()
        fileObj.close()
        
    def finds(self,lang,w):
        '''
        precondition: language,w
        returns True if the word was found
                False otherwise
        '''
        for i in range (0,len(self.__wordlist)):
            if self.__wordlist[i].get_lang()==lang and self.__wordlist[i].get_word()==w:
                return True
        return False
     
    def writefile(self,filename,WordList):
        """
        writes in a file the words from a list
        
        """
        fh=open(filename,"w")
        for i in range(0,len(WordList)):
            fh.write(str(WordList[i])+ " ")
        fh.close
    
    def readWords(self,fword):
        """
        the function reads all the words from a file and returns the list with the words
        """ 
        wordlist=[]
        fileObj=open(fword,"r")
        line=fileObj.readline().strip()
        while line !="":
            words=line.split(" ")
            for i in range(0,len(words)):
                wordlist.append(words[i])
            line=fileObj.readline().strip()
        fileObj.close()
        return wordlist
        
def testRepository():
    repo=WordsRepository("D:\examfp\exams\src\dictionary.txt")
    wordlist=repo.getAll()
    assert wordlist[0].get_id()=="1"
    assert wordlist[1].get_lang()=="En"
    assert wordlist[2].get_word()=="salut"

def testFindW():
    repo=WordsRepository("D:\examfp\exams\src\dictionary.txt")
    assert repo.finds("En", "Hello")==True
    assert repo.finds("Fr","garcon")==False
    assert repo.finds("Ro","salut")==True
testFindW()

testRepository()