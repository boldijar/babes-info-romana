'''

@author: radu
'''
from sorting_algorithms.generic_sort import GenericSort

class QuickSort(GenericSort):
    def __init__(self, col, key, reverse):
        super().__init__(col, key, reverse)
        
        
    def sort(self):
        self.col[:] = self.__quick_sort(self.col)
    
    def __quick_sort(self, l):
        if len(l) <= 1:
            return l
        p = [x for x in l if x == l[0]]
        left = [x for x in l if self._in_order(x, p[0], False)]
        right = [x for x in l if self._in_order(p[0], x, False)]
        return self.__quick_sort(left) + p + self.__quick_sort(right)
