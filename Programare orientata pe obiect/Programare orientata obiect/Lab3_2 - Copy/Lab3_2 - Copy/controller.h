#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "arrmanip.h"
#include <string>
using namespace std;



class Controller
{
public:

    /** Default constructor */
    Controller();
    /** Default destructor */
    virtual ~Controller();
    /** Get          */
    List<Tranzactie> GetList()
    {
        return list;
    }
    List<Tranzactie> GetListaVeche()
    {
        return listaVeche;
    }
    /****/
    void AddToList(struct Tranzactie, unsigned int);
    /****/
    void AddToList(struct Tranzactie);
    /****/
    void RemoveByDay(unsigned int);
    /****/
    void RemoveFromList(unsigned int);
    /****/
    void RemoveFromList(List<Tranzactie>&, unsigned int, unsigned int);
    /****/
    void RemoveFromList(unsigned int, unsigned int);
    /****/
    void ReplaceAll(List<Tranzactie>&, List<Tranzactie>&);
    /****/
    List<Tranzactie>& getGreaterThan(unsigned int);
    /****/
    List<Tranzactie>& getLessThan(unsigned int);
    /****/
    void RemoveIfIn(bool);
    /****/
    List<Tranzactie>& getType(bool);
    /****/
    List<Tranzactie>& getDayElements(unsigned int);
    /****/
    List<Tranzactie>& getElementsInOut(bool);
    /****/
    void FilterInOut(bool);
    /****/
    void FilterGreater(bool , float);
    /****/
    void CopyList();
    /****/
    void Undo();


protected:
    List<Tranzactie> list;
    List<Tranzactie> listaVeche;
private:
    bool checkEqual(Tranzactie elem1, Tranzactie elem2);
    bool checkNotEqual(Tranzactie elem1, Tranzactie elem2);
};

#endif // CONTROLLER_H
