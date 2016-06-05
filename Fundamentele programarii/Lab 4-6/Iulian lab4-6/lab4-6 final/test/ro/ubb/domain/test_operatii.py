'''
Created on Oct 21, 2014

@author: Iulian
'''

from src.ro.ubb.domain.operatii import adauga_cheltuiala, actualizeaza_cheltuiala, sterge_cheltuiala_de_un_anumit_tip,\
    sterge_cheltuieli_din_ziua_data, sterge_cheltuieli_de_la_pana_la,\
    cheltuieli_mai_mari_decat_suma, cheltuieli_dupa_suma_si_zi,\
    cheltuieli_de_un_anumit_tip, suma_totala_pentru_un_anumit_tip,\
    ziua_in_care_suma_cheltuita_e_maxima, cheltuieli_sortate_dupa_tip,\
    elimina_cheltuieli_de_un_anumit_tip,\
    elimina_cheltuieli_mai_mici_decat_o_suma, cheltuieli_cu_o_anumita_suma,\
    reface_ultima_cheltuiala
from src.ro.ubb.domain.cheltuiala import creeaza_cheltuiala, get_tip


def setUp():
    l=[]
    l.append(creeaza_cheltuiala(2, 130, "imbracaminte"))
    l.append(creeaza_cheltuiala(5, 300, "intretinere"))
    l.append(creeaza_cheltuiala(3, 150, "telefon"))
    l.append(creeaza_cheltuiala(4, 150, "imbracaminte"))
    l.append(creeaza_cheltuiala(4, 50, "imbracaminte"))
    return l

def test_adauga_cheltuiala():
    l = []
    undolist = []
    assert( len(l) == 0 )
    
    adauga_cheltuiala(l, creeaza_cheltuiala(1, 150, "mancare"), undolist)
    assert( len(l) == 1 )
    
    adauga_cheltuiala(l, creeaza_cheltuiala(1, 100, "telefon"), undolist)
    assert( len(l) == 2 )
    
def test_actualizeaza_cheltuiala():
    l = setUp()
    undolist = setUp()
    
    actualizeaza_cheltuiala(l, 2, "imbracaminte", 200, undolist)
    assert( l[0]["suma"] == 200 )
    
    actualizeaza_cheltuiala(l, 3, "telefon", 300, undolist)
    assert( l[2]["suma"] == 300 )
    
    actualizeaza_cheltuiala(l, 5, "intretinere", 200, undolist)
    assert( l[1]["suma"] == 200 )
    
def test_sterge_cheltuiala_de_un_anumit_tip():
    l=setUp()
    undolist = setUp()
    assert(len(l)==5)
    
    sterge_cheltuiala_de_un_anumit_tip(l, "telefon", undolist)
    assert(len(l) == 4)
    
    sterge_cheltuiala_de_un_anumit_tip(l, "imbracaminte", undolist)
    assert(len(l) == 1)
    
def test_sterge_cheltuieli_din_ziua_data():
    l=setUp()
    undolist = setUp()
    assert(len(l) == 5)
    
    sterge_cheltuieli_din_ziua_data(l,5, undolist)
    assert(len(l) == 4)
    
    sterge_cheltuieli_din_ziua_data(l, 4, undolist)
    assert(len(l) == 2)
    
def test_sterge_cheltuieli_de_la_pana_la():
    l=setUp()
    undolist = setUp()
    assert(len(l) == 5)
    
    sterge_cheltuieli_de_la_pana_la(l, 1, 2, undolist)
    assert(len(l) == 4)
    
    sterge_cheltuieli_de_la_pana_la(l, 3, 5, undolist)
    assert(len(l) == 0)
    
def test_cheltuieli_mai_mari_decat_suma():
    l = setUp()
    x = cheltuieli_mai_mari_decat_suma(l, 125)
    assert(len(x) == 4)
    
    x = cheltuieli_mai_mari_decat_suma(l, 400)
    assert(len(x) == 0)
    
    x = cheltuieli_mai_mari_decat_suma(l, 160)
    assert(len(x) == 1)
    

def test_cheltuieli_dupa_suma_si_zi():
    l = setUp()
    x = cheltuieli_dupa_suma_si_zi(l, 150, 3)
    assert(len(x) == 1)
    
    x = cheltuieli_dupa_suma_si_zi(l, 180, 4)
    assert(len(x) == 2)
    
    x = cheltuieli_dupa_suma_si_zi(l, 30, 5)
    assert(len(x) == 0)

def test_cheltuieli_de_un_anumit_tip():
    l=setUp()
    x = cheltuieli_de_un_anumit_tip(l, "imbracaminte")
    assert(len(x) == 3)
     
    x = cheltuieli_de_un_anumit_tip(l, "telefon")
    assert(len(x) == 1)

def test_suma_totala_pentru_un_anumit_tip():
    l=setUp()
    assert ( suma_totala_pentru_un_anumit_tip(l, "imbracaminte") == 330)
    assert (suma_totala_pentru_un_anumit_tip(l, "telefon") == 150)
    assert (suma_totala_pentru_un_anumit_tip(l, "abc") == 0)

def test_ziua_in_care_suma_cheltuita_e_maxima():
    l = setUp()
    
    zi = ziua_in_care_suma_cheltuita_e_maxima(l)
    assert ( zi == 5)
    
    l.append(creeaza_cheltuiala(4, 200, "imbracaminte"))
    zi = ziua_in_care_suma_cheltuita_e_maxima(l)
    assert (zi == 4)
    

def test_cheltuieli_cu_o_anumita_suma():
    l=setUp()
    x = cheltuieli_cu_o_anumita_suma(l, 150)
    assert( len(x) == 2)
    
    x= cheltuieli_cu_o_anumita_suma(l, 500)
    assert( len(x) == 0)
    
    x= cheltuieli_cu_o_anumita_suma(l, 50)
    assert( len(x) == 1)

def test_cheltuieli_sortate_dupa_tip():
    l = setUp()
    cheltuieli_sortate_dupa_tip(l)
    assert ( get_tip(l[0]) == "imbracaminte")
    assert ( get_tip(l[1]) == "imbracaminte")
    assert ( get_tip(l[2]) == "imbracaminte")
    assert ( get_tip(l[3]) == "intretinere")
    assert ( get_tip(l[4]) == "telefon")
    
def test_elimina_cheltuieli_de_un_anumit_tip():
    l=setUp()
    undolist = setUp()
    elimina_cheltuieli_de_un_anumit_tip(l, "telefon", undolist)
    assert(len(l) == 4)
    
    elimina_cheltuieli_de_un_anumit_tip(l, "imbracaminte", undolist)
    assert(len(l) == 1)

def test_elimina_cheltuieli_mai_mici_decat_o_suma():
    l=setUp()
    undolist = setUp()
    elimina_cheltuieli_mai_mici_decat_o_suma(l, 150, undolist)
    assert(len(l) == 3)
    
    elimina_cheltuieli_mai_mici_decat_o_suma(l, 400, undolist)
    assert(len(l) == 0)

def test_reface_ultima_cheltuiala():
    l = []
    undolist = []
    adauga_cheltuiala(l, creeaza_cheltuiala(1, 150, "mancare"), undolist)
    assert (len(l) == 1)
    reface_ultima_cheltuiala(l, undolist)
    assert (len(l) == 0)
    
    adauga_cheltuiala(l, creeaza_cheltuiala(1, 150, "mancare"), undolist)
    adauga_cheltuiala(l, creeaza_cheltuiala(3, 250, "mancare"), undolist)
    adauga_cheltuiala(l, creeaza_cheltuiala(4, 650, "telefon"), undolist)
    assert (len(l) == 3)
    reface_ultima_cheltuiala(l, undolist)
    assert (len(l) == 2)
    reface_ultima_cheltuiala(l, undolist)
    assert (len(l) == 1)