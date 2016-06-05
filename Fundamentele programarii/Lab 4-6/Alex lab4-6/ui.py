'''
Created on 30 oct. 2014

@author: Alex
'''
from tranzactie import *
from cont import *

def meniu_stergere(lista):
    meniu_sterge='''
    1.) Stergeti tranzactiile dintr-o zi data
    2.) Stergeti tranzactile dintr-un interval de zile
    3.) Stergeti tranzactiile de un anumit tip
    0.) Intoarcere meinu principal
    '''
    semafor = True
    while semafor == True:
        print (meniu_sterge)
        try:
            cmd = int (input("Optiunea: "))
            
            if cmd == 0:
                semafor = False
            elif cmd == 1:
                ziua = int(input("Dati numarul zilei pe care doriti sa o stergeti: "))
                sterge_zi(lista,ziua)
            elif cmd == 2:
                inceput = int(input("Dati ziua de inceput a perioadei ce o doriti stearsa: "))
                sfarsit = int(input("Dati ziua de sfarsit a perioadei ce o doriti stearsa: "))
                sterge_perioada(lista,inceput,sfarsit)
            elif cmd == 3:
                tip = input("Precizati tipul elementelor pe care le doriti sterse: ")
                if (tip == tipul[0] or tip == tipul[1]):
                    sterge_tip(lista,tip)
                else:
                    print("Tipul ales nu este corespunazator")
                
                
                
        except ValueError:
            print("Nu ati introdus o intrusctiune valida!")
        except KeyError:
            print("Nu ati introdus o intrusctiune valida!")

def meniu_adaugare(lista):
    meniu_adauga='''
    1.) Cititi n tranzactii
    2.) Adaugare tranzactie
    3.) Modificare tranzactie
    4.) Afisare tranzactii
    0.) Intoarcere meniu principal
    '''
    semafor = True
    options_adauga = {1:ui_citeste_lista,2:adaugare_lista,3:update_lista,4:afis}
    while semafor == True:
        print (meniu_adauga)
        try:
            cmd = int (input("Optiunea: "))
            
            if cmd == 0:
                semafor = False
            elif cmd == 2:
                print("Introduceti ziua , suma si tupul noului element")
                zi = int(input("ziua: "))
                suma = int(input("suma: "))
                tip = input("tipul: ")
                if (tip == tipul[0] or tip == tipul[1]):
                    options_adauga[cmd](lista,zi,suma,tip)
                else:
                    print("Tipul ales nu este corespunazator")
            elif cmd == 1:
                options_adauga[cmd](lista)
            elif cmd == 4:
                options_adauga[cmd](lista)
            elif cmd == 3:
                n = int(input("Dati elementul pe care doriti sa-l modificati: "))
                
                print("Introduceti ziua , suma si tupul noului element")
                zi = int(input("ziua: "))
                suma = int(input("suma: "))
                tip = input("tipul: ")
                if (tip == tipul[0] or tip == tipul[1]):
                    options_adauga[cmd](lista,zi,suma,tip,n)
                else:
                    print("Tipul ales nu este corespunazator")
                
        except ValueError:
            print("Nu ati introdus o intrusctiune valida!")
        except KeyError:
            print("Nu ati introdus o intrusctiune valida!")
            
            
def meniu_afisari(lista):
    #list = []
    meniu_afisari='''
Alege optiunea dorita:
1.) Afisare tranzactii cu suma mai mare de cat o suma data
2.) Afisare tranzactii cu suma mai marede cat o suma data dintr-o anmita zi
3.) Afisare tranzactii de un anumit tip
0.) Intoarcere meniu principal

'''
    semafor = True
    options={1:sume_mari,2:sume_mari_zi,3:tranzactie_tip}
    while semafor == True:
        print(meniu_afisari)
        try:
            cmd = int(input("Optiunea: "))
            if cmd == 0:
                semafor = False
                print("La revedere!")
            else:
                options[cmd](lista)
        except ValueError:
            print("Nu ati introdus o intrusctiune valida!")
        except KeyError:
            print("Nu ati introdus o intrusctiune valida!")
            
            
def meniu_rapoarte(lista):
    meniu = '''
    1.) Suma totala a tranzactiilor de un anumit tip
    2.) Soldul contului
    3.) Tipareste toate tranzactiile de un anumit tip ordonat dupa suma
    4.) Intoarcere meniu principal
    '''
    semafor = True
    while semafor == True:
        print(meniu)
        try:
            cmd = int(input("Optiunea: "))
            if cmd == 0:
                semafor = False
            elif cmd == 1:
                tip = input("Dati tipul")
                if (tip == tipul[0] or tip == tipul[1]):
                    print(suma_tip(lista, tip))
                else:
                    print("Tipul ales nu este corespunazator")
            elif cmd == 2:
                print(sold(lista))
            elif cmd == 3:
                tip = input("Dati tipul")
                if (tip == tipul[0] or tip == tipul[1]):
                    sortare_tranzactii_tip(lista, tip)
                else:
                    print("Tipul ales nu este corespunazator")
                
        
        except ValueError:
            print("Nu ati introdus o intrusctiune valida!")
        except KeyError:
            print("Nu ati introdus o intrusctiune valida!")
            
def meniu_filtre(lista):
    meniu = '''
    1.)Elimina toate tranzactiile de un anumit tip
    2.)Elimina tranzactii de un anumit tip mai mici de cat o suma data
    0.)Intoarcere meniu principal
    '''
    semafor = True
    while semafor == True:
        print(meniu)
        try:
            cmd = int(input("Optiunea: "))
            if cmd == 0:
                semafor = False
            elif cmd == 1:
                tip = input("Precizati tipul elementelor de sters: ")
                elimina_tip(lista, tip)
            elif cmd == 2:
                tip = input("Precizati tipul elementelor de sters: ")
                suma = int (input("Dati suma: "))
                elimin_mai_mici(lista, suma, tip)
        except ValueError:
            print("Nu ati introdus o intrusctiune valida!")
        except KeyError:
            print("Nu ati introdus o intrusctiune valida!")
                
                
        
 
def runUI():
    lista = []
    menu='''
Alege optiunea dorita:
1.) Submeniu adaugare
2.) Submeniu stergere
3.) Submeniu afisri
4.) Submeniu rapoarte
5.) Submeniu filtre
6.) Undo
0.) Parasire aplicatie

'''
    semafor = True
    options = {1:meniu_adaugare,2:meniu_stergere,3:meniu_afisari,4:meniu_rapoarte,5:meniu_filtre,6:undo}
    while semafor == True:
        print(menu)
        try:
            cmd = int(input("Optiunea: "))
            if cmd == 0:
                semafor = False
                print("La revedere!")
            else:
                options[cmd](lista)
        except ValueError:
            print("Nu ati introdus o intrusctiune valida!")
        except KeyError:
            print("Nu ati introdus o intrusctiune valida!")
        
runUI()
