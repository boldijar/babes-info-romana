'''

@author: radu
'''

class BacktrackingSolver(object):
    def __init__(self, first, consistent, is_solution, get_solution, next_elem, initial_value):
        self.__first = first
        self.__consistent = consistent
        self.__is_solution = is_solution
        self.__get_solution = get_solution
        self.__next_elem = next_elem
        self.__initial_value = initial_value

    
    def back_rec(self, x, n):
        el = self.__first(x)
        x.append(el)
        while el != None:
            x[len(x) - 1] = el
            if self.__consistent(x, n):
                if self.__is_solution(x, n):
                    yield self.__get_solution(x)
                else:
                    yield from self.back_rec(x[:], n)
            el = self.__next_elem(x)
    
    
    def back_iter(self, n):
        x = [self.__initial_value()]
        while len(x) > 0:
            el = self.__next_elem(x)
            while el != None:
                x[len(x) - 1] = el            
                if self.__consistent(x, n):
                    if self.__is_solution(x, n):
                        yield self.__get_solution(x)
                    else: 
                        x.append(self.__initial_value())
                        break
                el = self.__next_elem(x)
            if el is None: x = x[:-1]

