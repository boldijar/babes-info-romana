'''

@author: radu
'''

class Product(object):
    def __init__(self, product_id, name, price):
        self.__product_id = product_id
        self.__name = name
        self.__price = price
        
    @property
    def Id(self):
        return self.__product_id
    
    @property
    def name(self):
        return self.__name
    
    @property
    def price(self):
        return self.__price
    
    @name.setter        
    def name(self, name):
        self.__name = name

    @price.setter
    def price(self, price):
        self.__price = price

    def __str__(self):
        return str(self.Id) + " " + self.name + " " + str(self.price)

def test_product():
    p = Product(1, "p1", 1)
    assert p.Id == 1
    p.name = "p2"
    assert p.name == "p2"    
test_product()    
