'''
Created on 8 dec. 2014

@author: teo
'''
from domain.filme import Film



class RepoFilme():
    '''
    clasa care se ocupa cu extragerea si adaugarea listei de filme in si din fisiser
    numeFis = numele fisierului
    '''
    
    def __init__(self, numeFis):
        self.__NF = numeFis
        
        
    def modificare(self, filmN):
        '''
        modifica un film dupa ID
        id - idul de modificat
        filmN - obiectul Film pe care il punem in loc
        arunca AttributeError daca nu exista idul cautat
        '''
        lista = self.getAll()
        i=0
        eGasit = False
        for fi in lista:
            if filmN.getID() == fi.getID():
                eGasit = True
                break
            i+=1
        
        if eGasit == False:
            raise AttributeError("ID-ul nu exista.")
        
        lista[i] = filmN
        
        f = open(self.__NF, 'w') 
        for film in lista:
            strFilm = str(film.getID())+','+film.getTitlu()+','+str(film.getPret())+','+str(film.getNrLocuri())+'\n'
            f.write(strFilm)
        
        f.close()
        
        
    def update(self, film):
        '''
        metoda care adauga in fisier un film, iar daca nu exista fisierul, il creaza
        arunca ValueError daca exista deja un film cu ID-ul introdus
        '''
        lista = self.getAll()
        
        for f in lista:
            if f.getID() == film.getID():
                raise ValueError("ID-ul exista deja.")
        
        try:
            f = open(self.__NF, 'a')
        except IOError:
            f = open(self.__NF, 'w') #daca fisierul nu exista, il cream
        strFilm = str(film.getID())+','+film.getTitlu()+','+str(film.getPret())+','+str(film.getNrLocuri())+'\n'
        f.write(strFilm)
        f.close()
        
    def getAll(self):
        '''
        metoda ce returneaza o lista de obiecte Film care reprezinta toate filmele din fisier
        returneaza o lista de obiecte Film, iar daca fisierul nu exista, returneaza None
        '''
        
        try:
            f = open(self.__NF, 'r')
        except IOError:
            #fisierul nu exista
            return None
        lista = []
        linie = f.readline().strip()
        while linie != '':
            atrib = linie.split(',')
            if(len(atrib) == 4): #verificam daca este un film valid
                lista.append(Film(int(atrib[0]), atrib[1], float(atrib[2]), int(atrib[3])))
            linie = f.readline().strip()
        
        return lista
            

def testCreareRepo():
    open("filmetest.txt", 'w')
    repo = RepoFilme("filmetest.txt")
    repo.update(Film(47, 'De la specii', 15, 68))
    repo.update(Film(49, 'De la speci', 85, 85))
    lista = repo.getAll()
    assert lista[1].getID() == 49 and lista[1].getTitlu() == 'De la speci' and lista[1].getPret() == 85 and lista[1].getNrLocuri() == 85
    assert lista[0].getID() == 47 and lista[0].getTitlu() == 'De la specii' and  lista[0].getPret() == 15 and lista[0].getNrLocuri() == 68

def testModificareRepo():
    open("filmetest.txt", 'w')
    repo = RepoFilme("filmetest.txt")
    repo.update(Film(47, 'De la specii', 15, 68))
    repo.update(Film(49, 'De la speci', 85, 85))
    repo.modificare(Film(47, 'De la specii', 17, 69))
    lista = repo.getAll()
    print(lista[0])
    assert lista[0] == Film(47, 'De la specii', 17, 69)
    
testModificareRepo()
testCreareRepo()  