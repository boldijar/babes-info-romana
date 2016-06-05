'''

@author: radu

Python iterators.
'''
from s14p1.entities import Product


class Shop(object):
    def __init__(self):
        self.__items = []
        self.__pos = -1
        
    def add_item(self, item):
        self.__items.append(item)
    
    def __iter__(self):
        self.__pos = -1
        return self
    
    def __next__(self):
        self.__pos += 1
        if self.__pos == len(self.__items):
            raise StopIteration
        return self.__items[self.__pos]
            
        

    
if __name__ == "__main__":
    p1 = Product(1, "p1", 1)
    p2 = Product(2, "p2", 2)
    p3 = Product(3, "p3", 3)
     
    my_shop = Shop()
    my_shop.add_item(p1)
    my_shop.add_item(p2)
    my_shop.add_item(p3)
     
    for product in my_shop:
        print(product)
    
    print("--------")
    iterator = iter(my_shop)
    product = next(iterator)
    print(product)
    product = next(iterator)
    print(product)
    product = next(iterator)
    print(product)    
