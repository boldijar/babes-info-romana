'''
Created on 30 oct. 2014

@author: Alex
'''

def test_tranzactie():
    cont = create_tranzactie(22,350,"in")
    assert get_zi(cont) == 22
    assert get_suma(cont) == 350
    set_tip(cont,"out")
    assert get_tip(cont) == "out"
    
def create_tranzactie(zi,suma,tip):
    return {"zi":zi,"suma":suma,"tip":tip}

def get_zi(cont):
    return cont["zi"]

def get_suma(cont):
    return cont["suma"]

def get_tip(cont):
    return cont["tip"]

def set_zi(cont,zi):
    cont["zi"]=zi

def set_suma(cont,suma):
    cont["suma"]=suma

def set_tip(cont,tip):
    cont["tip"]=tip

def undo(lista):
    pass

test_tranzactie()
