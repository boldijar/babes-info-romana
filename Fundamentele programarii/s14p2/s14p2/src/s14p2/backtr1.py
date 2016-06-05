'''

@author: radu

Generate all sequences of n parentheses that close correctly.
 Example: n=4 there are two solutions: (()) and ()()
'''

def first(x):
    return 0

def consistent(x, n):
    z, u = 0, 0
    for e in x:
        if e == 0: z += 1
        if e == 1: u += 1
    if z > n // 2:return False
    return True if z >= u else False
 
def is_solution(x, n):
    return len(x) == n

def output_solution(x):
    s = ["(" if e == 0 else ")" for e in x]
    s = "".join(s)
    print(s)

def next_elem(x):
    if x[len(x) - 1] == 1:
        return None
    return x[len(x) - 1] + 1

def back_rec(x, n):
    el = first(x)
    x.append(el)
    while el != None:
        x[len(x) - 1] = el
        if consistent(x, n):
            if is_solution(x, n):
                output_solution(x)
            else:
                back_rec(x[:], n)
        el = next_elem(x)

def initial_value():
    return -1

def back_iter(n):
    x = [initial_value()]
    while len(x) > 0:
        el = next_elem(x)
        while el != None:
            x[len(x) - 1] = el            
            if consistent(x, n):
                if is_solution(x, n):
                    output_solution(x)
                else: 
                    x.append(initial_value())
                    break
            el = next_elem(x)
        if el is None: x = x[:-1]
                     
def backtr1(n):
    if n % 2 == 1:
        print("no solution")
        return    
    back_rec([], n)
#     back_iter(n)
 
backtr1(4)
