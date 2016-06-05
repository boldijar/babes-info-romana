'''

@author: radu

Python generators
'''
from s14p1.entities import Product

class Shop2(object):
    def __init__(self):
        self.__items = []
    
    def add_item(self, item):
        self.__items.append(item)
        
    @property
    def items(self):
        for item in self.__items:
            yield item

    @property
    def items2(self):
        return (item for item in self.__items)

if __name__ == '__main__':
    p1 = Product(1, "p1", 1)
    p2 = Product(2, "p2", 2)
    p3 = Product(3, "p3", 3)
    
    my_shop = Shop2()
    my_shop.add_item(p1)
    my_shop.add_item(p2)
    my_shop.add_item(p3)
    
    print(my_shop.items)
    for product in my_shop.items:
        print(product)
    
    print("---------------")
    iterator = iter(my_shop.items)
    product = next(iterator)
    print(product)
    product = next(iterator)
    print(product)
    product = next(iterator)
    print(product)
    
    print(my_shop.items2)
    for product in my_shop.items2:
        print(product)
        
    print("---------------")
    iterator = iter(my_shop.items2)
    product = next(iterator)
    print(product)
    product = next(iterator)
    print(product)
    product = next(iterator)
    print(product)