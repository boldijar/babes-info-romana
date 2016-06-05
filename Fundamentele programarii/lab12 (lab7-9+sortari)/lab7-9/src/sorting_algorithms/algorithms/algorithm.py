'''

@author: radu
'''
from enum import Enum, unique

from sorting_algorithms.algorithms.selection_sort import SelectionSort,\
    SelectionSortRec
from sorting_algorithms.algorithms.shake_sort import ShakeSort


@unique
class Algorithm(Enum):
    SELECTION_SORT = SelectionSort
    SHAKE_SORT = ShakeSort
    SELECTION_SORT_REC = SelectionSortRec