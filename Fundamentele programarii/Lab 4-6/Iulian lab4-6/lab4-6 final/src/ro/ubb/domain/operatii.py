'''
Created on Oct 21, 2014

@author: Iulian
'''

from src.ro.ubb.domain.cheltuiala import get_ziua, get_suma, get_tip
from copy import deepcopy #pentru lista de undo

def adauga_cheltuiala(l, s, undolist):
    l.append(s)
    
    lista_provizorie = deepcopy(l)
    undolist.append(lista_provizorie)

def actualizeaza_cheltuiala(l, zi, tip, c, undolist):
    '''
    functia actualizeaza cheltuiala(suma) pentru ziua si tipul precizat
    l-lista, zi-numar intreg, tip-cuvant, c-numar intreg
    '''
    for s in l:
        if get_ziua(s) == zi and get_tip(s) == tip:
            s["suma"] = c
    
    lista_provizorie = deepcopy(l)
    undolist.append(lista_provizorie)
    
'''
--------------Stergeri-----------
'''
            
def sterge_cheltuiala_de_un_anumit_tip(l, tip, undolist):
    '''
    functia sterge toate cheltuielile de un anumit tip precizat
    l-lista, tip-cuvant
    
    folosesc o lista auxiliara ,,rez" si pun in ea elementele care nu sunt de acel tip precizat
    apoi reactualizez lista ,,l" cu lista ,,rez"
    '''
    rez=[]
    for s in l:
        if get_tip(s) != tip:
            rez.append(s)
    l[:] = rez
    
    lista_provizorie = deepcopy(l)
    undolist.append(lista_provizorie)
    
def sterge_cheltuieli_din_ziua_data(l, zi, undolist):
    '''
    functia sterge toate cheltuielile dintr-o zi precizata
    l-lista, zi-numar intreg
    
    folosesc o lista auxiliara ,,rez" si pun in ea elementele care nu sunt din ziua precizata
    apoi reactualizez lista ,,l" cu lista ,,rez"
    '''
    rez=[]
    for s in l:
        if get_ziua(s) != zi:
            rez.append(s)
    l[:] = rez
    
    lista_provizorie = deepcopy(l)
    undolist.append(lista_provizorie)
    
def sterge_cheltuieli_de_la_pana_la(l, zi_inceput, zi_sfarsit, undolist):
    '''
    functia sterge toate cheltuielile pentru un interval de timp specificat
    l-lista, zi_inceput-numar intreg, zi_sfarsit-numar intreg
    
    folosesc o lista auxiliara ,,rez" si pun in ea elementele care nu sunt din intervalul [zi_ineput, zi_sfarsit]
    apoi reactualizez lista ,,l" cu lista ,,rez"
    '''
    rez=[]
    for s in l:
        if get_ziua(s) < zi_inceput or get_ziua(s) > zi_sfarsit:
            rez.append(s)
    l[:] = rez
    
    lista_provizorie = deepcopy(l)
    undolist.append(lista_provizorie)
    

'''
---------------Cautari-------------
'''

def cheltuieli_mai_mari_decat_suma(l, suma):
    '''
    functia returneaza o lista ,,aux'' toate cheltuielile mai mari decat o suma data
    l-lista, suma - numar intreg, aux - lista
    parcurg lista l si salvez in lista aux elementele listei l care sunt mai mari decat ,,suma"
    '''
    aux = []
    for s in l:
        if get_suma(s) > suma:
            aux.append(s)
    return aux
    
def cheltuieli_dupa_suma_si_zi(l, suma, zi):
    '''
    functia returneaza lista ,,aux'' toate cheltuielile mai mici decat o suma data si efectuate 
    inainte de o zi specificata
    l- lista, suma - numar intreg, zi - numar intreg, aux - lista
    parcurg lista l si salvez in lista ,,aux'' elementele care indeplinesc conditia specificata
    '''
    aux = []
    for s in l:
        if get_suma(s) < suma and get_ziua(s) < zi:
            aux.append(s)
    return aux

def cheltuieli_de_un_anumit_tip(l, tip):
    '''
    functia returneaza o lista ,,aux'' toate cheltuielile de un anumit tip
    l - lista, tip - cuvant, aux- lista
    parcurg lista l si memorez in lista ,,aux" elementele care indeplinesc conditia specificata
    '''
    aux = []
    for s in l:
        if(get_tip(s) == tip):
            aux.append(s)
    return aux    


'''
-----------------Rapoarte-----------
'''

def suma_totala_pentru_un_anumit_tip(l, tip):
    '''
    functia returneaza suma totala pentru un anumit tip de cheltuiala
    l - lista, tip - cuvant, suma_totala - numar intreg
    parcurg lista si adun la suma_totala elementele care sunt de acelasi tip cu cel specificat
    '''
    suma_totala = 0
    for s in l:
        if get_tip(s) == tip:
            suma_totala = suma_totala + get_suma(s)
    return suma_totala
    
def ziua_in_care_suma_cheltuita_e_maxima(l):
    '''
    functia returneaza prin variabila ,,zi" ziua in care suma cheltuita este maxima
    suma_maxima - numar intreg, variabila care retine suma_maxima dintr-o anumita zi
    suma_partiala - numar intreg, variabila care retine suma partiala dintr-o anumita zi si o compara cu suma maxima
    d - numar intreg, variabila care retine ziua din lista de cheltuieli 
    '''
    suma_maxima = 0
    zi = 0
    for s in l:
        d = get_ziua(s)
        suma_partiala = 0
        for j in l:
            if get_ziua(j) == d:
                suma_partiala = suma_partiala + get_suma(j)
            if suma_maxima < suma_partiala:
                suma_maxima = suma_partiala
                zi = d
    return zi

def cheltuieli_cu_o_anumita_suma(l,suma):
    '''
    functia returneaza prin lista ,,aux" toate cheltuielile cu o anumita suma data
    l - lista, suma - numar intreg, aux = lista
    parcurg lista l si salvez in lista aux elementele listei care indeplinesc conditia specificata anterior
    '''
    aux = []
    for s in l:
        if(get_suma(s) == suma):
            aux.append(s)
    return aux


def cheltuieli_sortate_dupa_tip(l):
    '''
    functia sorteaza elementele liste dupa tip, in ordine alfabetica
    l - lista
    functia foloseste metoda elevului pentru ordonare
    '''
    for i in range(0, len(l)):
        for j in range(0, len(l)):
            if get_tip(l[i]) < get_tip(l[j]):
                l[i], l[j] = l[j], l[i]
    


'''
----------------------Filtrare-------------------
'''

def elimina_cheltuieli_de_un_anumit_tip(l,tip, undolist):
    '''
    functia elimina din lista toate cheltuielile de un anumit tip precizat
    l - lista, tip - cuvant
    am folosit o functie auxiliara ,,rez" in care pun elementele ce NU indeplinesc conditia specificata
    apoi copiez lista auxiliara in lista l
    '''
    rez = []
    for s in l:
        if get_tip(s) != tip :
            rez.append(s)
    l[:] = rez


def elimina_cheltuieli_mai_mici_decat_o_suma(l,suma, undolist):
    '''
    functia sterge toate cheltuielile mai mici decat o suma data
    l-lista, suma - numar intreg
    
    folosesc o lista auxiliara ,,rez" si pun in ea elementele care sunt mai mari sau egale decat acea suma
    apoi actualizez lista l cu noua lista ,,rez"
    '''
    rez = []
    for s in l:
        if get_suma(s) >= suma:
            rez.append(s)
    l[:] = rez


'''
-----------------------------Undo----------------
'''

def reface_ultima_cheltuiala(l, undolist):
    '''
    Fuctia ajuta la ,,reintoarcerea programului", reface ultima cheltuiala
    '''
    if len(undolist) >= 0:
        try:    
            undolist.pop()
            l[:] = undolist[-1]
        except IndexError:
            l[:] = []

