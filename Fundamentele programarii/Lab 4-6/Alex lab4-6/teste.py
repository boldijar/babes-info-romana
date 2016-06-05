'''
Created on 30 oct. 2014

@author: Alex
'''
from cont import *

def test_sortare():
    tranzactie1 = create_tranzactie(22,350,"in")
    tranzactie2 = create_tranzactie(1,1000,"in")
    tranzactie3 = create_tranzactie(10,90,"out")
    lista = [tranzactie1 , tranzactie2 , tranzactie3]
    sortare_lista(lista)
    assert lista == [tranzactie2 , tranzactie3 , tranzactie1]
    
                
test_sortare()          

def test_adaugare():
    tranzactie1 = create_tranzactie(22,350,"in")
    tranzactie2 = create_tranzactie(1,1000,"in")
    tranzactie3 = create_tranzactie(10,90,"out")
    lista = [tranzactie1 , tranzactie2 , tranzactie3]
    adaugare_lista(lista,40,350,"out")
    assert lista == [tranzactie2,tranzactie3,tranzactie1,{"zi":40,"suma":350,"tip":"out"}]
    
test_adaugare()

def test_update():
    tranzactie1 = create_tranzactie(22,350,"in")
    lista = [tranzactie1]
    update_lista(lista,40,350,"out",0)
    assert lista == [{"zi":40,"suma":350,"tip":"out"}]
        
test_update() 


def test_sterge_zi():
    tranzactie1 = create_tranzactie(22,350,"in")
    tranzactie2 = create_tranzactie(1,1000,"in")
    tranzactie3 = create_tranzactie(80,90,"out")
    lista = [tranzactie1 , tranzactie2 , tranzactie3]
    sterge_zi(lista, 1)
    assert lista == [{"zi":22,"suma":350,"tip":"in"},{"zi":80,"suma":90,"tip":"out"}]
           
test_sterge_zi()

def test_cautare():
    
    '''
    Verific daca functia de cautare functioneaza corect
    '''
    tranzactie1 = create_tranzactie(22,350,"in")
    tranzactie2 = create_tranzactie(1,1000,"in")
    tranzactie3 = create_tranzactie(80,90,"out")
    lista = [tranzactie1 , tranzactie2 , tranzactie3]
    
    assert cautare_zi(lista, 22) == True
    assert cautare_zi(lista, 1) == True
    assert  cautare_zi(lista, 100) == False

        
test_cautare()
        
def test_sterge_perioada():
    tranzactie1 = create_tranzactie(22,350,"in")
    tranzactie2 = create_tranzactie(1,1000,"in")
    tranzactie3 = create_tranzactie(80,90,"out")
    lista = [tranzactie1 , tranzactie2 , tranzactie3]
    sterge_perioada(lista, 1 , 22)
    assert lista == [ {"zi":80,"suma":90,"tip":"out"} ]

    
test_sterge_perioada()

def test_suma_tip():
    tranzactie1 = create_tranzactie(22,350,"in")
    tranzactie2 = create_tranzactie(1,1000,"in")
    tranzactie3 = create_tranzactie(80,90,"out")
    lista = [tranzactie1 , tranzactie2 , tranzactie3]
    
    assert suma_tip(lista,"in") == 1350
    assert suma_tip(lista,"out") == 90

test_suma_tip()  

def test_sold():
    tranzactie1 = create_tranzactie(22,350,"in")
    tranzactie2 = create_tranzactie(1,30,"in")
    tranzactie3 = create_tranzactie(80,400,"out")
    lista = [tranzactie1 , tranzactie2 , tranzactie3]
    assert sold(lista) == -20
    
test_sold()



def test_elimina_tip():
    cont1 = create_tranzactie(22,350,"in")
    cont2 = create_tranzactie(1,1000,"in")
    cont3 = create_tranzactie(80,90,"out")
    lista = [cont1 , cont2 , cont3]
    elimina_tip(lista , "in")
    assert lista == [ {"zi":80,"suma":90,"tip":"out"} ]
    elimina_tip(lista, "out")
    assert lista == [  ]

test_elimina_tip()

    
def test_elimin_mai_mici():
    cont1 = create_tranzactie(22,350,"in")
    cont2 = create_tranzactie(1,1000,"in")
    cont3 = create_tranzactie(80,90,"out")
    lista = [cont1 , cont2 , cont3]
    elimin_mai_mici(lista , 400 , "in")
    assert lista == [ {"zi":1,"suma":1000,"tip":"in"},{"zi":80,"suma":90,"tip":"out"} ]

    
test_elimin_mai_mici()
