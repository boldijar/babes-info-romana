def citire(n):
    v = []
    for i in range(0,n):
        x = int(input("dati elemnt: "))
        v.append(x)
    return v
def cifre(a,b):
    v1 = [0,0,0,0,0,0,0,0,0,0]
    v2 = [0,0,0,0,0,0,0,0,0,0]
    cont = 0
    
    while a > 0:
        v1[a%10] = v1[a%10] + 1
        a=int(a/10)
    while b > 0:
        v2[b%10] = v2[b%10] + 1
        b = int(b/10)
    for i in range(0,10):
        if(v1[i] != 0 and v2[i] != 0):
            cont = cont + 1

    if cont >= 2:
        return True
    else:
        return False
        

def secv(n):
    pstop = 0
    last = 0 
    maxim = 1
    d = 1
    v = citire(n)
    for i in range(0,n-1):
        if(cifre(v[i],v[i+1]) == True):
           pstop = i + 1
           d = d + 1
           if d > maxim:
               maxim = d
               last = pstop
        else:
            d = 1
    for i in range (last - maxim + 1,last + 1):
        print(v[i])
               
      
def main():
    n=int(input("dati n: "))
    
    secv(n)
        
