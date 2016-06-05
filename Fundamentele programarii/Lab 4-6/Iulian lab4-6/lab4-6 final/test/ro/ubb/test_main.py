'''
Created on Oct 21, 2014

@author: Iulian
'''

from test.ro.ubb.domain.test_operatii import test_actualizeaza_cheltuiala, test_adauga_cheltuiala, \
test_sterge_cheltuiala_de_un_anumit_tip, test_sterge_cheltuieli_din_ziua_data, test_sterge_cheltuieli_de_la_pana_la,\
    test_cheltuieli_mai_mari_decat_suma, test_cheltuieli_de_un_anumit_tip,\
    test_suma_totala_pentru_un_anumit_tip, test_cheltuieli_cu_o_anumita_suma,\
    test_cheltuieli_sortate_dupa_tip, test_elimina_cheltuieli_de_un_anumit_tip,\
    test_elimina_cheltuieli_mai_mici_decat_o_suma, test_reface_ultima_cheltuiala
from test.ro.ubb.domain.test_operatii import test_cheltuieli_dupa_suma_si_zi
from test.ro.ubb.domain.test_operatii import test_ziua_in_care_suma_cheltuita_e_maxima

def test_all():
    test_actualizeaza_cheltuiala()
    test_adauga_cheltuiala()
    test_sterge_cheltuiala_de_un_anumit_tip()
    test_sterge_cheltuieli_din_ziua_data()
    test_sterge_cheltuieli_de_la_pana_la()
    test_cheltuieli_mai_mari_decat_suma()
    test_cheltuieli_dupa_suma_si_zi()
    test_cheltuieli_de_un_anumit_tip()
    test_suma_totala_pentru_un_anumit_tip()
    test_ziua_in_care_suma_cheltuita_e_maxima()
    test_cheltuieli_cu_o_anumita_suma()
    test_cheltuieli_sortate_dupa_tip()
    test_elimina_cheltuieli_de_un_anumit_tip()
    test_elimina_cheltuieli_mai_mici_decat_o_suma()
    test_reface_ultima_cheltuiala()

    
if __name__ == '__main__':
    test_all()