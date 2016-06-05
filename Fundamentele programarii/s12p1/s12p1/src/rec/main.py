'''

@author: radu

#Recursion.
'''

def merge(l1, l2):
    """Merge two sorted lists.
    """
    if len(l1) == 0:
        return l2
    if len(l2) == 0:
        return l1
    if l1[0] < l2[0]:
        return [l1[0]] + merge(l1[1:], l2)
    return [l2[0]] + merge(l1, l2[1:])

def return_last(l):
    """Return the last element of a list.
    """
    if len(l) == 1:
        return l[0]
    return return_last(l[1:])

def delete_last(l):
    """Return the list without the last element.
    """
    if len(l) == 1:
        return []
    return [l[0]] + delete_last(l[1:])

def add_last(l, e):
    if len(l) == 0:
        return [e]
    return [l[0]] + add_last(l[1:], e)

def length(l):
    if len(l) == 0:
        return 0
    return 1 + length(l[1:])

def is_odd_len(l):
    """Determine whether a list has an odd number of elements, but without computing the length.
    """
    if len(l) == 0:
        return False
    return not is_odd_len(l[1:])

def alt_sum(l):
    """Determine the alternating sum of a list, i.e., the number obtained by summing all list elements
    of even order and substracting all list elements having an odd order (the list is 0-based). 
    """
    if len(l) == 0:
        return 0
    if len(l) == 1:
        return l[0]
    return l[0] - l[1] + alt_sum(l[2:])

def alt_sum2(l):
    """Determine the alternating sum of a list, i.e., the number obtained by summing all list elements
    of even order and substracting all list elements having an odd order (the list is 0-based). 
    """
    if len(l) == 0:
        return 0
    if len(l) == 1:
        return l[0]
    return l[0] - alt_sum(l[1:])

def product(l):
    if len(l) == 0:
        return 1
    return l[0] * product(l[1:])

def power(x, n):
    if n == 0:
        return 1
    return x * power(x, n - 1)

def power2(x, n):
    if n == 0:
        return 1
    p = power2(x, n // 2)
    if n % 2 == 0:        
        return p * p
    return x * p * p

def invert(l):
    """Return the list elements in reversed order.
    """
    if len(l) == 0:
        return l
    return invert(l[1:]) + [l[0]]

def max_elem(l):
    """Determine the maximal element of a list.
    """
    if len(l) == 1:
        return l[0]
    return max(l[0], max_elem(l[1:]))
    
def gcd(a, b):
    """Return the greatest common divisor between two numbers by succesive substractions.
    """
    if a == b:
        return a
    if a > b:
        return gcd(a - b, b)
    return gcd(a, b - a)

def gcd_list(l):
    """Return the greatest common divisor between the elements of a list.
    """
    if len(l) == 1:
        return l[0]
    return gcd(l[0], gcd_list(l[1:]))

def max_list(l):
    """Return the maximum element of a list.
    """
    if len(l) == 1:
        return l[0]
    
    return max(l[0], max_list(l[1:]))


def replace_with_list(l, e, l2):
    """Replace all occurrences of an element e from a list l with the elements from another list l2. 
    """
    if l == []:
        return []
    if l[0] != e:
        return [l[0]] + replace_with_list(l[1:], e, l2)
    return l2 + replace_with_list(l[1:], e, l2)

def replace_with_list_2(l, e, l2, l3):
    """Replace all occurrences of an element e from a list l with the elements from another list l2.
    Without concatenating the entire list l2 to the result.
    l3 - an auxiliary list equal to the initial list l2.
    """
    if l == []:
        return []
    if l[0] != e:
        return [l[0]] + replace_with_list_2(l[1:], e, l2, l3)
    if l2 == []:
        return replace_with_list_2(l[1:], e, l3, l3)
    
    return [l2[0]] + replace_with_list_2(l, e, l2[1:], l3)

def replace_with_list_3(l, e, l2):
    """Replace all occurrences of an element e from a list l with the elements from another list l2.
    Without concatenating the entire list l2 to the result.
    Without using an auxiliary list.
    """
    if l == []:
        return []
    if l[0] != e:
        return [l[0]] + replace_with_list_3(l[1:], e, l2)
    if l2 == []:
        return []
    return [l2[0]] + replace_with_list_3([l[0]], e, l2[1:]) + replace_with_list_3(l[1:], e, l2)


if __name__ == '__main__':
    assert (merge([1, 4, 4, 8], [5, 8, 9]) == [1, 4, 4, 5, 8, 8, 9])
    
    assert(return_last([1, 5, 3, 2]) == 2)
    
    assert(delete_last([2, 5, 4, 1]) == [2, 5, 4])

    assert(add_last([2, 1, 3], 7) == [2, 1, 3, 7])

    assert(length([2, 1, 3]) == 3)
    
    assert(is_odd_len([2, 1, 3]) == True)

    assert(alt_sum([6, 4, 7, 5, 1]) == 5)
    
    assert(alt_sum2([6, 4, 7, 5, 1]) == 5)
    
    assert(product([4, 8, 2, 2]) == 128)

    assert(power(2, 5) == 32)
    
    assert(power2(2, 5) == 32)

    assert(invert([1, 2, 3]) == [3, 2, 1])

    assert(max_elem([2, 6, 3, 1]) == 6)

    assert(gcd_list([8, 12, 16, 24]) == 4)
    
    assert max_list([1, 2, 5, 3, 6, 8, 4, 2]) == 8
    
    assert replace_with_list([2, 3, 4, 3, 5], 3, [10, 11]) == [2, 10, 11, 4, 10, 11, 5]
    
    assert replace_with_list_2([2, 3, 4, 3, 5], 3, [10, 11], [10, 11]) == [2, 10, 11, 4, 10, 11, 5]
    
    assert replace_with_list_3([2, 3, 4, 3, 5], 3, [10, 11]) == [2, 10, 11, 4, 10, 11, 5]
    
    print("OK")
