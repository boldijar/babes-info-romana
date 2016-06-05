'''
Created on Dec 17, 2014

@author: Iulian
'''

#from sorting_algorithms.algorithms.algorithm import Algorithm
from sorting_algorithms.sorting import Sorting
from sorting_algorithms.algorithms.algorithm import Algorithm

class Person:
    def __init__(self, name, age):
        self.__name = name
        self.__age = age
            
    @property
    def name(self):
        return self.__name
      
    @property
    def age(self):
        return self.__age
      
    def __str__(self):
        return self.name + " " + str(self.age)


def test_selection_sort():
    '''
    test for SELECTION SORT
    '''
    l = [2, 1, 3]
    Sorting.sort(l)
    assert(l == [1, 2, 3])
    
    Sorting.sort(l, reverse = True)
    assert (l == [3,2,1] )
    
    l = [2,1,2,3,1]
    Sorting.sort(l)
    assert l == [1,1,2,2,3]
    
    Sorting.sort(l, reverse = True)
    assert l == [3,2,2,1,1]
    
       
    p1 = Person("p1", 1)
    p2 = Person("p2", 2)
    p3 = Person("p3", 3)
    p4 = Person("p1", 2)
    
    
    # sort by name asc
    l = [p3, p2, p1, p4]
    Sorting.sort(l, key=lambda x:x.name)
    assert(l == [p4, p1, p2, p3])
    
    # sort by age desc
    l = [p3, p2, p4, p1]
    Sorting.sort(l, key=lambda x:x.age, reverse=True)
    assert(l == [p3, p4, p2, p1])
    
    # sort by age asc
    l = [p3, p2, p4, p1]
    Sorting.sort(l, key=lambda x:x.age)
    assert(l == [p1, p4, p2, p3])
    
    # sort by name,age ascending
    l = [p3, p2, p1, p4]
    Sorting.sort(l, key=lambda x:(x.name, x.age))
    assert(l == [p1, p4, p2, p3])
    
    # sort by name ascending and by age descending    
    def person_less_than(p1, p2): 
        """name ascending, age descending
        """
        if p1.name == p2.name:
            return p1.age > p2.age
        return p1.name < p2.name

    Person.__lt__ = person_less_than
    Person.__gt__ = not person_less_than
    l = [p3, p2, p1, p4]
    Sorting.sort(l)
    assert(l == [p4, p1, p2, p3])
    print("Selection sort ok")
    
def test_shake_sort():
    '''
    test for SHAKE_SORT
    '''
    l = [2, 1, 3]
    Sorting.sort(l, algorithm = Algorithm.SHAKE_SORT)
    assert(l == [1, 2, 3])
    
    Sorting.sort(l, reverse = True, algorithm = Algorithm.SHAKE_SORT)
    assert (l == [3,2,1] )
    
    l = [2,1,2,3,1]
    Sorting.sort(l, algorithm = Algorithm.SHAKE_SORT)
    assert l == [1,1,2,2,3]
    
    Sorting.sort(l, reverse = True, algorithm = Algorithm.SHAKE_SORT)
    assert l == [3,2,2,1,1]
    
       
    p1 = Person("p1", 1)
    p2 = Person("p2", 2)
    p3 = Person("p3", 3)
    p4 = Person("p1", 2)
    
    
    # sort by name asc
    l = [p3, p2, p1, p4]
    Sorting.sort(l, key=lambda x:x.name, algorithm = Algorithm.SHAKE_SORT)
    assert(l == [p1, p4, p2, p3])
    
    # sort by age desc
    l = [p3, p2, p4, p1]
    Sorting.sort(l, key=lambda x:x.age, reverse=True, algorithm = Algorithm.SHAKE_SORT)
    assert(l == [p3, p2, p4, p1])
    
    # sort by age asc
    l = [p3, p2, p4, p1]
    Sorting.sort(l, key=lambda x:x.age, algorithm = Algorithm.SHAKE_SORT)
    assert(l == [p1, p2, p4, p3])
    
    # sort by name,age ascending
    l = [p3, p2, p1, p4]
    Sorting.sort(l, key=lambda x:(x.name, x.age), algorithm = Algorithm.SHAKE_SORT)
    assert(l == [p1, p4, p2, p3])
    
    # sort by name ascending and by age descending    
    def person_less_than(p1, p2): 
        """name ascending, age descending
        """
        if p1.name == p2.name:
            return p1.age > p2.age
        return p1.name < p2.name

    Person.__lt__ = person_less_than
    Person.__gt__ = not person_less_than
    l = [p3, p2, p1, p4]
    Sorting.sort(l, algorithm = Algorithm.SHAKE_SORT)
    assert(l == [p4, p1, p2, p3])

    print("Shake sort ok")
    
    
    
if __name__ == '__main__':
    test_selection_sort()
    test_shake_sort()