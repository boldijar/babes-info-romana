'''

Se dă o listă de numere întregi
a1,...an.
Determinaţi toate posibilităţile de a insera
operatorul de + şi – între numere astfel încât rezultatul
expresiei este pozitiv
.
'''

def first(x):
    return 0

def consistent(x, n):
    return len(x) <= n
 
def is_solution(lst, x, n):
    if len(x) < n:
        return False
    s = lst[0]
    for i in range(1, len(lst)):
        if x[i - 1] == 0:
            s = s - lst[i]
        else:
            s = s + lst[i]
    return s > 0

def output_solution(lst, x):
    for i in range(len(lst) - 1):
        op = "- "if x[i] == 0 else "+ " 
        print(lst[i], op, end="")
    print(lst[-1])

def next_elem(x):
    if x[len(x) - 1] == 1:
        return None
    return x[len(x) - 1] + 1

def back_rec(lst,x, n):
    el = first(x)
    x.append(el)
    while el != None:
        x[len(x) - 1] = el
        if consistent(x, n):
            if is_solution(lst,x, n):
                output_solution(lst,x)
            else:
                back_rec(lst,x[:], n)
        el = next_elem(x)

def initial_value():
    return -1

def back_iter(lst, n):
    x = [initial_value()]
    while len(x) > 0:
        el = next_elem(x)
        while el != None:
            x[len(x) - 1] = el            
            if consistent(x, n):
                if is_solution(lst, x, n):
                    output_solution(lst, x)
                else: 
                    x.append(initial_value())
                    break
            el = next_elem(x)
        if el is None: x = x[:-1]
                     
def backtr1(lst, n):
    print("rec")
    back_rec(lst,[], n)
    print("iter")
    back_iter(lst, n)
lst = [2, 4, 7, 1] 
backtr1(lst, len(lst) - 1)
        
