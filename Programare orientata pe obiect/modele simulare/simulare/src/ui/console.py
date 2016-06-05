'''
Created on Dec 10, 2014

@author: Iulian
'''

class Console():
    def __init__(self, contr):
        self.__contr = contr
    
    def __sterge_tipp(self):
        tip = input("tip: ")
        self.__contr.sterge_tip(tip)
        print("Bicicletele de tipul respectiv au fost sterse")
    
    def __sterge_max(self):
        self.__contr.sterge_max()
     
    def UI(self):
        while(True):
            print("Meniu\n\
            1. sterge tip \n\
            2. sterge max \n\
            x. iesire")
            op = input("Optiune: ")
            if op == '1':
                self.__sterge_tipp()
            if op == '2':
                self.__sterge_max()
            if op =='x':
                break
        