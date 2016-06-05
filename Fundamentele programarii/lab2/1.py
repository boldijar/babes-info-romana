def prim(n):
    if n==2: return True
    if n%2==0: return False
    for i in range(3, n, 2):
        if n%i==0: return False
    return True
 
def main():
    n= int(input("n="))
    p=0
    i=n+1
    while p==0:
        if prim(i) == True:
            print(i)
            p=1
        i=i+1

main()
