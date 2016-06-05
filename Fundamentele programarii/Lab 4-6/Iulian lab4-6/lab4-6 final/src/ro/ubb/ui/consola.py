'''
Created on Oct 22, 2014

@author: Iulian
'''

from src.ro.ubb.domain.operatii import adauga_cheltuiala, actualizeaza_cheltuiala, sterge_cheltuiala_de_un_anumit_tip, \
    sterge_cheltuieli_de_la_pana_la, sterge_cheltuieli_din_ziua_data,\
    cheltuieli_mai_mari_decat_suma, cheltuieli_dupa_suma_si_zi,\
    cheltuieli_de_un_anumit_tip, suma_totala_pentru_un_anumit_tip,\
    cheltuieli_cu_o_anumita_suma, cheltuieli_sortate_dupa_tip,\
    elimina_cheltuieli_de_un_anumit_tip, reface_ultima_cheltuiala,\
    elimina_cheltuieli_mai_mici_decat_o_suma,\
    ziua_in_care_suma_cheltuita_e_maxima
from src.ro.ubb.domain.cheltuiala import creeaza_cheltuiala, get_suma, get_tip, get_ziua

def print_options():
    '''
    afisez meniul cu optiuni
    '''
    print("1. Afiseaza cheltuieli \n\
2. Adauga o noua cheltuiala \n\
3. Actualizeaza cheltuiala \n\
4. Sterge toate cheltuielile pentru ziua data \n\
5. Sterge cheltuielile pentru un interval de timp \n\
6. Sterge toate cheltuielile de un anumit tip \n\
7. Tipareste toate cheltuielile mai mari decat o suma data \n\
8. Tipareste toate cheltuielile efectuate inainte de o zi data si mai mici decat o suma data \n\
9. Tipareste toate cheltuielile de un anumit tip \n\
10. Tipareste suma totala pentru un anumit tip de cheltuiala \n\
11. Gaseste ziua in care suma cheltuita e maxima \n\
12. Tipareste toate cheltuielile ce au o anumita suma \n\
13. Tipareste cheltuielile sortate dupa tip \n\
14. Elimina toate cheltuielile de un anumit tip \n\
15. Elimina toate cheltuielile mai mici decat o suma data \n\
16. Reface ultima operatie \n\
x. Iesire")


def afisare_cheltuiala(s):
    '''
    afisez o singura cheltuiala de tipul (zi, suma, tip)
    '''
    print("({0},{1},{2})".format(get_ziua(s), get_suma(s), get_tip(s) ) )
    
def afisare_cheltuieli(l, undolist):
    '''
    afisez lista cu cheltuieli, daca nu exista cheltuieli in lista afisez mesajul ,,lista este goala"
    '''
    if( len(l) == 0 ):
        print("Lista este goala")
    else:
        for s in l:
            afisare_cheltuiala(s)
            
def ui_adauga_cheltuiala(l, undolist):
    ziua = 0
    suma = 0
    tip = ""
    try:
        ziua = int(input("Ziua: "))
        suma = float(input("Suma cheltuita: "))
        tip = input("Tip cheltuiala: ")
    except ValueError:
        print("Ati introdus date gresite")
        ziua = 0
        suma = 0
        tip = ""
    s = creeaza_cheltuiala(ziua, suma, tip)
    adauga_cheltuiala(l, s, undolist)
    print("Cheltuiala a fost adaugata")
 
def ui_actualizeaza_cheltuiala(l, undolist):
    ziua = 0
    suma = 0
    tip = ""
    try:
        ziua = int(input("Selectati ziua: "))
        tip = input("Selectati tipul: ")
        suma = int(input("Introduceti noua suma: "))
        actualizeaza_cheltuiala(l, ziua, tip, suma, undolist)
    except ValueError:
        print("Ati introdus date gresite")
    print("Ati actualizat cheltuiala")


def ui_sterge_cheltuiala_de_un_anumit_tip(l, undolist):
    tip = ""
    try:
        tip = input("Tipul: ")
    except ValueError:
        print("Ati introdus date gresite")
    sterge_cheltuiala_de_un_anumit_tip(l, tip, undolist)

def ui_sterge_cheltuieli_din_ziua_data(l, undolist):
    zi = 0
    try:
        zi = int(input("Ziua: "))
    except ValueError:
        print("Ati introdus date gresite")
    sterge_cheltuieli_din_ziua_data(l, zi, undolist)

def ui_sterge_cheltuieli_de_la_pana_la(l, undolist):
    zi_inceput = 0
    zi_sfarsit = 0
    try:
        zi_inceput = int(input("Ziua de inceput: "))
        zi_sfarsit = int(input("ziua de sfarsit: "))
    except ValueError:
        print("Ati introdus date gresite")
    sterge_cheltuieli_de_la_pana_la(l, zi_inceput, zi_sfarsit, undolist)

def ui_cheltuieli_mai_mari_decat_suma(l, undolist):
    suma = 0
    try:
        suma = int(input("Suma: "))
    except ValueError:
        print("Ati introdus date gresite")
    aux = cheltuieli_mai_mari_decat_suma(l, suma)
    for s in aux:
        afisare_cheltuiala(s)
   
def ui_cheltuieli_dupa_suma_si_zi(l, undolist):
    suma = 0
    zi = 0
    try:
        zi = int(input("Ziua: "))
        suma = int(input("Suma: "))
    except ValueError:
        print("Ati introdus date gresite")
    aux = cheltuieli_dupa_suma_si_zi(l, suma, zi)
    for s in aux:
        afisare_cheltuiala(s)


def ui_cheltuieli_de_un_anumit_tip(l, undolist):
    tip = ""
    try:
        tip = input("Tipul: ")
    except ValueError:
        print("Ati introdus date gresite")
    aux = cheltuieli_de_un_anumit_tip(l, tip)
    for s in aux:
        afisare_cheltuiala(s)
        
def ui_suma_totala_pentru_un_anumit_tip(l, undolist):
    tip = ""
    try:
        tip = input("Tipul: ")
    except ValueError:
        print("Ati introdus date gresite")
    print(suma_totala_pentru_un_anumit_tip(l,tip))

def ui_ziua_in_care_suma_cheltuita_e_maxima(l, undolist):
    zi = ziua_in_care_suma_cheltuita_e_maxima(l)
    print("Ziua in care suma cheltuita e maxima este: " + str(zi))

def ui_cheltuieli_cu_o_anumita_suma(l, undolist):
    suma = 0
    try:
        suma = int(input("Suma: "))
    except ValueError:
        print("Ati introdus date gresite")
    aux = cheltuieli_cu_o_anumita_suma(l,suma)
    for s in aux:
        afisare_cheltuiala(s)

def ui_elimina_cheltuieli_de_un_anumit_tip(l, undolist):
    tip = ""
    try:
        tip = input("Tipul: ")
    except ValueError:
        print("Ati introdus date gresite")
    elimina_cheltuieli_de_un_anumit_tip(l,tip, undolist)


def ui_cheltuieli_sortate_dupa_tip(l, undolist):
    try:
        cheltuieli_sortate_dupa_tip(l)
    except IndexError:
        print("Lista este goala")
    afisare_cheltuieli(l, undolist)
    
def ui_elimina_cheltuieli_mai_mici_decat_o_suma(l, undolist):
    suma = 0
    try:
        suma = int(input("Suma: "))
    except ValueError:
        print("Ati introdus date gresite")
    elimina_cheltuieli_mai_mici_decat_o_suma(l,suma, undolist)


def ui_reface_ultima_cheltuiala(l, undolist):
    reface_ultima_cheltuiala(l, undolist)
    print("Lista a fost refacuta cu cheltuielile anterioare")
    
def run():
    l = []
    undolist = []
    optiuni = {1:afisare_cheltuieli, 2:ui_adauga_cheltuiala, 3:ui_actualizeaza_cheltuiala, 
               4: ui_sterge_cheltuieli_din_ziua_data, 5:ui_sterge_cheltuieli_de_la_pana_la,
               6:ui_sterge_cheltuiala_de_un_anumit_tip, 7:ui_cheltuieli_mai_mari_decat_suma,
               8:ui_cheltuieli_dupa_suma_si_zi, 9:ui_cheltuieli_de_un_anumit_tip, 
               10:ui_suma_totala_pentru_un_anumit_tip, 11:ui_ziua_in_care_suma_cheltuita_e_maxima,
               12:ui_cheltuieli_cu_o_anumita_suma, 13:ui_cheltuieli_sortate_dupa_tip,
               14:ui_elimina_cheltuieli_de_un_anumit_tip, 15:ui_elimina_cheltuieli_mai_mici_decat_o_suma,
               16:ui_reface_ultima_cheltuiala}
    
    while True:
        print_options()
        optiune = input("Optiune: ")
        if optiune == "x":
            break
        try:
            optiune = int(optiune)
            optiuni[optiune](l, undolist)
        except ValueError:
            print("Optiune invalida")
        except KeyError:
            print("Optiunea aleasa nu este implementata")
            