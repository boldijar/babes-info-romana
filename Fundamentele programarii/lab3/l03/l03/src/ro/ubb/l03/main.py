'''

@author: radu

Find the maximal length sequence with the property that
a) x[i] < x[i+1] < ... < x[i+p]
b) contains only even numbers

Use e menu with the following options:
1 - read a list of integers
2 - find the maximal length sequence a
3 - find the maximal length sequence b
x - exit

'''


def condition_increasing(lst, i, p, l):
    if l > 0 and lst[i] > lst[i - 1]:
        return True
    if i < len(lst) - 1 and p == -1 and lst[i] < lst[i + 1]:
        return True 
    return False

def condition_even(lst, i, p, l):
    return True if lst[i] % 2 == 0 else False
    
    

def find_sequence(lst, condition):
    [p, pmax] = [-1] * 2
    [l, lmax] = [0] * 2
    for i in range(len(lst)):
        if condition(lst, i, p, l):
            if l == 0:
                p = i
            l += 1
        elif l > lmax:
            [pmax, lmax] = [p, l]
            p, l = -1, 0
        else: 
            p, l = -1, 0
    if l > lmax:
        [pmax, lmax] = [p, l]
    return (p, l) if l > lmax else (pmax, lmax)
                
def read_list(lst):
    l = []
    n = int(input("n="))
    for _ in range(n):
        e = int(input())
        l.append(e)
    lst[:] = l

def ui_increasing_sequence(lst):
    (p, l) = find_sequence(lst, condition_increasing)
    print(lst[p:p + l])

def ui_even_sequence(lst):
    (p, l) = find_sequence(lst, condition_even)
    print(lst[p:p + l])

def print_options():
    print("1 - read a list of integers\n\
2 - find the maximal length sequence a\n\
3 - find the maximal length sequence b\n\
x - exit")


def run():
    lst = []
    options = {1:read_list, 2:ui_increasing_sequence, 3:ui_even_sequence}
    while True:
        print_options()
        opt = input("option=")
        if opt == "x":
            break
        try:
            opt = int(opt)
            options[opt](lst)
        except ValueError:
            print("Invalid input.")
        except KeyError:
            print("This option is not yet implemented.")        
        

def test_condition_even():
    lst = [9, 4, 5]
    assert(condition_even(lst, 1, 0, 0) == True)
#     lst = []
#     assert(condition_even(lst, 2, 0, 0) == True)


def test_all():
    test_condition_even()


if __name__ == '__main__':
    test_all()
    run()
