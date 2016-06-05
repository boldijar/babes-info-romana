'''
Created on 30 oct. 2014

@author: Alex
'''
tipul = ["in","out"]
from tranzactie import *
undolist = []
from copy import deepcopy

def ui_citeste_lista(lista):
    '''
fac citirea unor tranzactii din tranzactie facand exceptia unor erori
'''
    try:
        n = int(input("Dati numarul de elemnte al listei: "))
        if(n > 0):
            i = 0
            while i < n:
                zi = int(input("ziua: "))
                suma = int(input("suma: "))
                tip = input("tipul: ")
                if(zi <= 0 or zi <= 31):
                    print("Ziua nu poate di mai mica ca 0")
                    
                else:
                    if (tip == tipul[0] or tip == tipul[1]):
                
                        tranzactie = create_tranzactie( zi , suma , tip )
                        lista.append( tranzactie )
                                        
                        i = i + 1
                        print("")
                    else:
                        print("tip nepotrivit,reintroduceti o tranzactie de tipul in sau out")
                        print("")
                    print("")
                    
                        
            sortare_lista( lista )
            
            global undolist
            lista_provizorie = deepcopy(lista)
            undolist.append(lista_provizorie)
    except ValueError:
        print("Introduceti un numar!")
        
        
def sortare_lista(lista):
    '''
    Sortez lista tranzactiilor in functie de zi
    '''
    
    for i in range( 0 , len(lista) ):
        for j in range( i + 1 , len(lista) ):
            if( get_zi(lista[i]) > get_zi(lista[j]) ):
                lista[i] , lista[j] = lista[j] , lista[i]

def adaugare_lista(lista,zi,suma,tip):
    '''
    Adauga un element in lisa
    '''
    
    tranzactie = create_tranzactie(zi,suma,tip)
    lista.append(tranzactie)
    sortare_lista(lista)
    global undolist
    lista_provizorie = deepcopy(lista)
    undolist.append(lista_provizorie)
  


def update_lista(lista,zi,suma,tip,elem_modificat):
    '''
    Modifaca un element specificat din lista
    '''
    try:
        
        if elem_modificat > len(lista):
            print("Nu exista aceasta tranzactie")
        else:

            set_zi(lista[elem_modificat] , zi)
            set_suma(lista[elem_modificat] , suma)
            set_tip(lista[elem_modificat] , tip)
            
            sortare_lista(lista)
            lista_provizorie = deepcopy(lista)
            global undolist
            
            undolist.append(lista_provizorie)
            
            #print(lista_provizorie)
    except ValueError:
        print("Nu exista tranzactia dorita!")
        
    except IndexError:
        print("Introduceti un numar!")
               

def afis(lista):
    '''
    Afiseaza lista
    '''
    for tranzactie in range( 0 , len(lista) ):
        print( lista[tranzactie] )


def cautare_zi(lista,x):
    """
    caut in lista o tranzactie care sa fie efectuata in ziua x
    rezultatul functiei este unul de tip boolean care returneaza True
    daca exista vre-o tranzactie facuta in ziua x si False in caz tranzactierar
    """
    for i in range( 0 , len(lista) ):
        if get_zi( lista[i] ) == x:
            return True
        
    return False

      
def sterge_zi(lista,ziua):
    
    """
    Sterg tranzactiile efectuate intr-o zi data prin parametrul ziua
    """
    lista_provizorie = []
    try:
        
        if cautare_zi( lista , ziua ) == False:
            print("")
            print("Nu exista ziua ceruta")
        else:
            lista1 = []
            for i in range( 0 , len(lista) ):
                if get_zi( lista[i] ) != ziua:
                    lista1.append(lista[i])
            lista[:] = lista1
            lista_provizorie = deepcopy(lista)
            global undolist    
            undolist.append(lista_provizorie)
            print("")
            print("Tranzactiile din ziua x au fost sterse")    
    except ValueError:
        print("Introduceti un numar!")


    
def sterge_perioada(lista,inceput,sfarsit):
    '''
    Sterg toate tranzictiile aflate in perioada aflata intre
    inceput si sfarsit - variabile citite
    
    '''
  
    lista1 = []
    for i in range( 0 , len(lista) ):
        if get_zi( lista[i] ) < inceput or get_zi( lista[i] ) > sfarsit:
            lista1.append(lista[i])
    lista[:] = lista1
    lista_provizorie = deepcopy(lista)
    global undolist 
    undolist.append(lista_provizorie)
    

def sterge_tip(lista,tipul):
    '''
    Sterg elementele de un tip precizat
    Tipul este un string
    '''
    
    lista1 = []
    for i in range( 0 , len(lista) ):
        if get_tip(lista[i]) != tipul:
            lista1.append(lista[i])
    lista[:] = lista1
    lista_provizorie = deepcopy(lista)
    global undolist
    undolist.append(lista_provizorie)
    
def sume_mari(lista):
    '''
    Afisez tranzactiile de valori mai mari de cat o suma data
    '''
    try:
        suma = int(input("Dati suma: "))
        for i in range( 0 , len(lista) ):
            if get_suma(lista[i]) > suma:
                print (lista[i])
                
    except ValueError:
        print("Introduceti un numar!")
    
    
def sume_mari_zi(lista):
    '''
    Afiseaza tranzacitiile mai mari de o suma data 
    care s-au efectuat intr-o zi data
    
    '''
    try:
        zi = int(input("Dati ziua: "))
        suma = int(input("Dati suma: "))
        for i in range( 0 , len(lista) ):
            if (get_zi(lista[i]) == zi and get_suma(lista[i]) > suma):
                print (lista[i])
                
    except ValueError:
        print("Introduceti un numar!")
    
def tranzactie_tip(lista):
    '''
    Afiseaza tranzactiile de un anumit tip
    '''
    tip = input("Dati tipul: ")
    if (tip == tipul[0] or tip == tipul[1]):
        for i in range( 0 , len(lista) ):
                if (get_tip(lista[i]) == tip):
                    print (lista[i])
    else:
        print("Tipul dat nu exista")
        

def suma_tip(lista,tip):
    '''
    Se face suma tranzacriilor de un anumit tip
    '''
    suma = 0
    for i in range ( 0 , len(lista) ):
        if get_tip(lista[i]) == tip:
            suma = suma + get_suma(lista[i])
    return suma


def sold(lista):
    soldul = suma_tip(lista,"in") - suma_tip(lista,"out")
    return soldul
 
        
def sortare_tranzactii_tip(lista,tip):
    '''
    Sortez tranzactiile de un anumit tip  dupa suma lor
    '''
    #lista1 = []
    for i in range( 0 , len(lista) ):
        for j in range( i + 1 , len(lista) ):
            if( get_suma(lista[i]) > get_suma(lista[j]) ):
                lista[i] , lista[j] = lista[j] , lista[i]
    for i in range( 0 , len(lista) ):
        if get_tip(lista[i]) == tip:
            print(lista[i])
            
    
    
def elimina_tip(lista,tip):
    '''
    Sterg elemntele de un tip specificat
    '''
    
    lista1 = []
    for i in range ( 0 , len(lista) ):
        if get_tip(lista[i]) != tip:
            lista1.append( lista[i] )
    lista[:] = lista1
    lista_provizorie = deepcopy(lista)
    global undolist
    undolist.append(lista_provizorie)


    
def elimin_mai_mici(lista,suma,tip):
    '''
    Elimin toate tranzactiile de un anumit tip mai mici de cat o suma data
    '''
  
    lista1 = []
    for i in range ( 0 , len(lista) ):
        
        if (get_tip(lista[i]) == tip and get_suma(lista[i]) > suma) or get_tip(lista[i]) != tip:
            lista1.append( lista[i] )
            
    lista[:] = lista1
    lista_provizorie = deepcopy(lista)
    global undolist
    undolist.append(lista_provizorie)
    
def undo(lista):
    '''
    Fuctia de undo ajuta la reintoarcerea programului
    '''
    global undolist
    if len(undolist) >= 0:
        try:
            
            undolist.pop()
            lista[:] = undolist[-1]
            
        except IndexError:
            lista[:] = []
            
    else:
        print("lista n-are elemente")
    print(lista)
        
    
    
    #print(undolist)