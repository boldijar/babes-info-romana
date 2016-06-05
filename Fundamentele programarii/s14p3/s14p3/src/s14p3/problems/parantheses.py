'''

@author: radu
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

def get_solution(x):
    s = ["(" if e == 0 else ")" for e in x]
    s = "".join(s)
    return s

def next_elem(x):
    if x[len(x) - 1] == 1:
        return None
    return x[len(x) - 1] + 1

def initial_value():
    return -1

