'''

@author: radu
'''

class Console(object):
    def __init__(self, bs):
        self.__bs = bs
        

    def __print_options(self):
        print("n - Next solution \n\
x - eXit \
        ")
    
    
    def run_menu(self):
#         sol = self.__bs.back_rec([], 6)
        sol = self.__bs.back_iter(6)        
        while True:
            self.__print_options()
            opt = input("option=")
            if opt == "x":
                break
            elif opt == "n":
                try:
                    print(next(sol), "\n")
                except StopIteration as si:
                    print("no more solutions; ", si)
            else:
                print("Invalid option")
        
