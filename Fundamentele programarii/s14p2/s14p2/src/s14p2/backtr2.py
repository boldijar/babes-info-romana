'''

@author: radu

Generate all sequences of n parentheses that close correctly.
 Example: n=4 there are two solutions: (()) and ()()
'''

def parentheses_rec(res, left, right, pairs):
    if left == pairs and right == pairs:
        print(res)
    if left < pairs:
        parentheses_rec(res + "(", left + 1, right, pairs)
    if left > right:
        parentheses_rec(res + ")", left, right + 1, pairs)

#===================================================================================================================
        
def is_solution(bit, n):
    k = 0
    for i in range(n):        
        k -= 1 if bit & (1 << i) else -1
        if k < 0: return False                
    return (k == 0)

def output_solution(bit, n):
    s = ""
    for i in range(n):
        s += ")" if bit & (1 << i) else "("
    print(s)
        
def parentheses_iter(n):
    [output_solution(bit, n) for bit in range(0, 1 << n) if is_solution(bit, n)]  

def gen_parentheses(n):
    if n % 2 == 1:
        print("no is_solution")
        return
    parentheses_rec("", 0, 0, n // 2)
#     parentheses_iter(n)
    
gen_parentheses(4)
    
    
    
