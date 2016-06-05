'''
Created on Oct 21, 2014

@author: Iulian
'''

def creeaza_cheltuiala(ziua, suma, tip):
    return {"ziua":ziua, "suma":suma, "tip":tip}

def get_ziua(s):
    return s["ziua"]

def get_suma(s):
    return s["suma"]

def get_tip(s):
    return s["tip"]