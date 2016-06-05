'''

@author: radu
'''
from sorting_algorithms.algorithms.algorithm import Algorithm


class Sorting(object):
    
    @staticmethod
    def sort(col, key=None, reverse=False, algorithm=Algorithm.BUBBLE_SORT):
        sorting_alg = algorithm.value(col, key, reverse)
        sorting_alg.sort()
        
        

