'''
Created on Jan 23, 2013

@author: Maria
'''
class Word:
    def __init__(self,id,lang,word):
        self.__id=id
        self.__lang=lang
        self.__word=word
    
    def get_id(self):
        '''
        returns the id of the word object
        '''
        return self.__id


    def get_lang(self):
        '''
        returns the language of a word object
        '''
        return self.__lang


    def get_word(self):
        '''
        returns the word of a Word Object
        '''
        return self.__word


    def set_id(self, value):
        '''
        gives a new value to the id of a Word
        '''
        self.__id = value


    def set_lang(self, value):
        '''
        gives a new value to the language of a Word
        '''
        
        self.__lang = value


    def set_word(self, value):
        '''
        gives a new value to a word 
        '''
        self.__word = value

    def __str__ (self):
        '''
        returns a Word as a String
        '''
        return str(self.get_id())+" "+str(self.get_lang())+" "+str(self.get_word())


def testWord():
    word=Word("1","Ro","Salut")
    assert word.get_id()=="1"
    assert word.get_lang()=="Ro"
    assert word.get_word()=="Salut"
    
    word.set_id("5")
    assert word.get_id()=="5"
    word.set_lang("Fr")
    assert word.get_lang()=="Fr"
    word.set_word("bonjour")
    assert word.get_word()=="bonjour"
    
testWord()
    