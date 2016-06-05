'''

@author: radu
'''
from enum import Enum, unique

from sorting_algorithms.algorithms.bubble_sort import BubbleSort, BubbleSort2
from sorting_algorithms.algorithms.insertion_sort import InsertionSort, \
    InsertionSortRec
from sorting_algorithms.algorithms.merge_sort import MergeSort
from sorting_algorithms.algorithms.quick_sort import QuickSort


@unique
class Algorithm(Enum):
    BUBBLE_SORT = BubbleSort
    BUBBLE_SORT2 = BubbleSort2
    INSERTION_SORT = InsertionSort
    INSERTION_SORT_REC = InsertionSortRec
    QUICK_SORT = QuickSort
    MERGE_SORT=MergeSort
    
