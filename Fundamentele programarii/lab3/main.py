'''
Created on Oct 12, 2014

@author: Iulian
'''

def citire_lista(lista):
    '''Citim lista cu n elemente'''
    n=int(input("Dati numarul de elemente: "))
    v=[]
    print("Dati elementele: ")
    for i in range(0,n):
        x = int(input())
        v.append(x)
    lista[:] = v

def cel_putin_doua_cifre_distincte_comune(a, b):
    '''
    Verificam daca doua elemente au cel putin doua cifre distincte comune
    daca au cel putin doua cifre distincte comune, returnam valoarea ,,True",
    respectiv ,,False" in caz contrar"
    '''
    f1=[0,0,0,0,0,0,0,0,0,0]
    f2=[0,0,0,0,0,0,0,0,0,0]
    contor = 0
    while a != 0:
        f1[a%10] = f1[a%10] + 1
        a = int(a/10)
    
    while b!=0:
        f2[b%10] = f2[b%10] + 1
        b = int(b/10)
    
    for i in range(0,10):
        if f1[i] != 0 and f2[i] != 0:
            contor = contor + 1
    
    if contor >= 2:
        return True
    else:
        return False
    
def secv_de_elem_cu_cifre_distincte_comune(lista):
    '''
    Cautam secventa de lungime maxima care are proprietatea ca oricare doua
    elemente consecutive au cel putin doua cifre distincte comune
    Daca exista, printam secventa de lungime maxima,
    in caz contrat afisam mesajul ,,Nu exista secventa cu proprietatea ceruta"
    '''
    pstop = 0
    last = 0 
    maxim = 1
    d = 1
    for i in range(0,len(lista)-1):
        if(cel_putin_doua_cifre_distincte_comune(lista[i],lista[i+1]) == True):
            pstop = i + 1
            d = d + 1
            if d > maxim:
                maxim = d
                last = pstop
        else:
            d = 1
    if maxim == 1:
        print("Nu exista secventa cu proprietatea ceruta")
    else:
        for i in range (last - maxim + 1,last + 1):
            print(lista[i])
            
def meniu_optiuni():
    print("    1.Citire lista de numere intregi\n\
    2. Secventa de lungime maxima cu proprietatea ca oricare doua elemente consecutive au cel putin 2 cifre distincte comune\n\
    3. Secventa de lungime maxima cu proprietatea ca reprezinta o secventa sub forma de munte\n\
    4. Iesire")

def secv_munte(lista):
    pass

def main():
    lista=[]
    optiuni = {1:citire_lista, 2:secv_de_elem_cu_cifre_distincte_comune, 3: secv_munte}
    while True:
        meniu_optiuni()
        x=int(input("Optiune: "))
        if x==4:
            print("La revedere")
            break
        optiuni[x](lista)
        
main()