'''

@author: radu
'''
from sorting_algorithms.generic_sort import GenericSort

class InsertionSort(GenericSort):
    def __init__(self, col, key, reverse):
        super().__init__(col, key, reverse)
    
    def sort(self):
        for i in range(1, len(self.col)):
            p = self.col[i]
            j = i - 1
            while j >= 0 and self._in_order(p, self.col[j]):
                self.col[j + 1] = self.col[j]
                j -= 1
            self.col[j + 1] = p
            
class InsertionSortRec(GenericSort):
    def __init__(self, col, key, reverse):
        super().__init__(col, key, reverse)
        
    def sort(self):
        self.col[:] = self.__ins_sort(self.col)
    
    def __ins_sort(self, l):
        if len(l) == 0:
            return []
        return self.__insert_elem(l[0], self.__ins_sort(l[1:]))
    
    def __insert_elem(self, elem, l):
        """Inserts elem in the sorted list l such that l remains sorted.
        """
        if len(l) == 0:
            return [elem]
        if self._in_order(elem, l[0]):
            return [elem] + l
        return [l[0]] + self.__insert_elem(elem, l[1:])
            
