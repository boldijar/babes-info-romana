'''

@author: radu

Test pyhton generators.
'''

def hello_generator():
    print("hello")
    yield 1
    print("world")
    yield 2

def f():
    hg = hello_generator()
    print(hg)
    
    it = next(hg)
    print("bla")    
    print(it)
    
    it = next(hg)
    print("bla")    
    print(it)
     
    print("----------------------------")
    hg = hello_generator()
    for elem in hg:
        print(elem)
        
    print("say hello----------------------------")
    for elem in hg:
        print(elem)
    print("bye")    
    
        
    

if __name__ == '__main__':
    f()
