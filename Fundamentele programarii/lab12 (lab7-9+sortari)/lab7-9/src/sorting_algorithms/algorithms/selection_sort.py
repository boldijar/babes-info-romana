'''
Created on Dec 17, 2014

@author: Iulian
'''

from sorting_algorithms.generic_sort import GenericSort

class SelectionSort(GenericSort):
    def __init__(self,col,key,reverse):
        super().__init__(col,key,reverse)
    
    def sort(self):
        """
        sort the element of the list
        """
        for i in range(0,len(self.col)-1):
            ind = i
            #find the smallest element in the rest of the list
            for j in range(i+1,len(self.col)):
                if self._in_order(self.col[j], self.col[ind]):
                    self.col[j], self.col[ind] = self.col[ind], self.col[j]

 
class SelectionSortRec(GenericSort):
    pass
#     def __init__(self, col, key, reverse):
#         super().__init__(col,key,reverse)
#      
#     def sort(self):
#         self.col[:] = self.sort_rec( self.col, 0)
#      
#     def sort_rec(self,l, i):
#         if i >= len(self.col) -1:
#             return
#         ind = i
#         for j in range(i+1,len(self.col)):
#             if self._in_order(self.col[j], self.col[ind]):
#                 ind = j
#         self.col[j], self.col[ind] = self.col[ind], self.col[j]
#         return self.sort_rec(self.col, i+1)