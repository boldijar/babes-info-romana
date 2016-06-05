'''
@author: Iulian

    P3. Cheluieli de familie
        Scrieți o aplicație care gestionează cheltuielie de familie efectuate intr-o lună. Pentru o cheltuială se vor
        retine ziua (din luna), suma, tipul cheltuielii (5 categorii: mancare, întreținere, înbrăcăminte, telefon, altele).
    Aplicația să permită efectuarea repetată a următoarelor operații:
1. Adaugă cheltuială
    a. adaugă o nouă cheluială (se specifică ziua, suma, tipul)
    b. actualizează cheluială (se specifică ziua, suma, tipul)
2. Ștergere.
    a. Șterge toate cheltuielile pentru ziua dată
    b. Ștege cheltuielile pentru un interval de timp (se dă ziua de început și sfârșit, se sterg 
        toate cheltuielile pentru perioada dată)
    c. Șterge toate cheltuielile de un anumit tip
3. Căutări.
    a. Tipărește toate cheltuielile mai mari decât o sumă dată
    b. Tipărește toate cheltuielile efectuate înainte de o zi dată și mai mici decât o sumă (se 
        dă suma și ziua, se tipăresc toate cheltuielile mai mici ca suma dată și efectuate 
        înainte de ziua specificată)
    c. tipărește toate cheltuielile de un anumit tip.
4. Rapoarte.
    a. Tipărește suma totală pentru un anumit tip de cheltuială
    b. Găsește ziua în care suma cheltuită e maximă
    c. Tipărește toate cheltuielile ce au o anumită sumă
    d. Tipărește cheltuielile sortate după tip
5. Filtrare.
    a. Elimină toate cheltuielile de un anumit tip
    b. Elimină toate cheltuielile mai mici decăt o sumă dată
6. Undo
    a. Reface ultima operație (lista de cheltuieli revine ce exista înainte de ultima operație
        care a modificat lista).
'''


from src.ro.ubb.ui.consola import run

if __name__ == '__main__':
    run()