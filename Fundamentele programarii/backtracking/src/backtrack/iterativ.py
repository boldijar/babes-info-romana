'''
Created on 22 dec. 2014

@author: Narcis2007
Se dă o listă de numere întregi a1,...an, determinați toate sub-secvențele cu lungime mai
mare decât 2 cu proprietatea că: numerele sunt în ordine crescătoare şi numerele
consecutive au cel puţin o cifră în comun.
'''




def solutie(l):
    n=len(l)
    
    if n==4:
        return True
    
    return False
    
def bun(l):
    
    n=len(l)
    ok=1
    if n!=2:
        for i in range(1,n-1):
            if l[i]!=l[i+1]-1:
                ok=0
            if ok==0:
                return False
    return True

def cerinta(l,st):
    n=len(st)
    m=len(l)
    if n>2 and m>1:
        ok=1
        ok2=0
        for i in range(1,n-1):
            a=l[st[i]-1]
            b=l[st[i+1]-1]
            c= str(b)
            if a>b:
                ok=0
            
            while a>0:
                uc=a%10
                
                if str(uc) in c:
                    ok2=ok2+1
                a=a//10
            if ok2==0:
                ok=0
        if ok==1:
            lf=[]
            for i in range(1,n):
                lf.append(l[st[i]-1])
            print(lf)
            
        
    

def backtracking(l):
    '''
    structura bkt pentru submultimi-fara if solutie si else
    '''
    st=[0]
    k=1
    st.append(0)
    while k>0:
        
        if st[k]<len(l):
            st[k]=st[k]+1
            if bun(st):
                
                cerinta(l,st)
                k=k+1
                st.append(0)
        else:
            k=k-1
            st.pop()
            



l=[12,23,32,33,4,5,45,7,177,777]
backtracking(l)
