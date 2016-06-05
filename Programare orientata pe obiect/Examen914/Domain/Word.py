'''
Created on Jan 24, 2013

@author: Vlad Mihai
'''
class Word:
    def __init__(self,id,language,wd):
        self._id= id
        self._lang = language
        self._wd= wd
        
    def getId(self):
        return self._id
    def getLanguage(self):
        return self._lang
    def getWord(self):
        return self._wd
    def __str__(self):
        return (str(self.getId()) + " " + str(self.getLanguage()) + " " + str(self.getWord()))
def test():
    w = Word("1", "En", "are")
    assert w.getWord() == "are"
test()