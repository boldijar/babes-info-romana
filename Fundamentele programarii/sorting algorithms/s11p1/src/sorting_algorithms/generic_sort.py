'''

@author: radu
'''
from abc import abstractmethod, ABCMeta


class GenericSort(metaclass=ABCMeta):
    
    def __init__(self, col, key, reverse):
        self.__col = col
        self.__key = key
        self.__reverse = reverse
        
    @property
    def col(self):
        return self.__col
    
    @property
    def key(self):
        return self.__key
    
    @key.setter
    def key(self, key):
        self.__key = key
    
    @property
    def reverse(self):
        return self.__reverse
    
    @abstractmethod
    def sort(self):
        pass
    
    def _in_order(self, e1, e2, eq=True):
        if self.key is None:
            self.key = lambda x:x        
        if self.key(e1) == self.key(e2):
            return eq
        if not self.reverse:
            return self.key(e1) < self.key(e2)
        return self.key(e1) > self.key(e2)
