'''
Created on Dec 17, 2014

@author: Iulian
'''
from sorting_algorithms.generic_sort import GenericSort

'''
complexitatea este O(n*n) atat in cazul defavorabil cat si in cazul mediu. cazul cel mai favorabil este O(n),
cand sirul este ordonat
totusi complexitatea se poate apropia de O(n), in cazul in care elementele se afla la o distanta minima (k)
fata de pozitia pe care urmeaza sa fie mutat, astfel ar fi o complexitate O(k*n)
'''

class ShakeSort(GenericSort):
    def __init__(self,col,key,reverse):
        super().__init__(col,key,reverse)
    
    def sort(self):
        up = range(len(self.col) -1)
        while True:
            for indices in (up, reversed(up)):
                swapped = False
                for i in indices:
                    if not self._in_order(self.col[i], self.col[i+1] ):
                        self.col[i], self.col[i+1] = self.col[i+1], self.col[i]
                        swapped = True
                if not swapped:
                    return