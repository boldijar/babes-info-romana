'''
Created on Jan 24, 2013

@author: Vlad Mihai
'''
from Controller.Controller import *
class UI:
    def __init__(self,controller):
        self._control = controller
    def getControl(self):
        return self._control
    def Console(self):
       while True: 
            print "Press 0 to exit"
            print "Press 1 to add a Word to the dictionary"
            print "Press 2 to spell a text"
            print "Press 3 to check the text from a file"
            c = raw_input("Select Menu:")
            if(c == "0"):
                exit()
            elif c == "1":
                i = raw_input("Select the ID").strip()
                lang = raw_input("Select the language:").strip()
                word = raw_input("Select the Word:").strip()
                q = self.getControl().addWord(i,lang,word)
                if(q == "Error"):
                    print "Data that you have introduced are incorrect!!"
            elif c == "2":
                l = raw_input("Select Language:")
                t = raw_input("Text: ")
                q = self.getControl().SpellText(l,t)
                for i in q:
                    print i
            elif c == "3":
                i = raw_input("Input file name:")
                lang = raw_input("Language:")
                o = raw_input("Output file")
                self.getControl().CheckFile(i, lang, o)
                
                
            