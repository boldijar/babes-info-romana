#include <iostream>
#include <float.h>
#include "controller.h"
#include "arrmanip.h"


void MakeIntArrayNull(int* arr, int length)
{
    for(int i=0; i<length; i++)
        arr[i]=0;
}

Controller::Controller()
{
    //ctor
}

Controller::~Controller()
{
    //dtor
}

void Controller::AddToList(Tranzactie e)
{
    CopyList();
    list.addLast(e);
}

void Controller::AddToList(Tranzactie e, unsigned int pos)
{
    Tranzactie temp;
    List<Tranzactie>::iterator it = list.begin();
    if(pos >= (unsigned)list.countElements()+1)
    {
        list.addLast(e);
    }
    else
    {


        while(it.hasNext() != 0)
        {
            if(pos == 1)
            {
                temp = it.getElement();
                it.setElement(e);
                e=temp;
                it.nextElement();
            }
            else
            {
                pos--;
                it.nextElement();
            }
        }
        //it.setElement(e);
        temp = it.getElement();
        it.setElement(e);
        list.addLast(temp);
    }
}

void Controller::RemoveByDay(unsigned int day){
    List<Tranzactie>::iterator it2 = list.begin();
    List<Tranzactie>::iterator it1 = list.begin();
    int count = list.countElements();
    for (int i=0; i<count; i++){
        if (it2.getElement().day == day){
            if (checkEqual(it1.getElement(), it2.getElement())){
                list.removeFirst();
                it1 = list.begin();
                it2 = it1;
            }
            else{
                //Node<Tranzactie> n1 = it1.getNode();
                //Node<Tranzactie> n2 = it2.getNode();
                it1.getNode()->setNext(it2.getNode()->getNext());
                list.setCount(list.countElements()-1);
                it2 = it1;
                it2.nextElement();
            }
        }
        else{
            it1 = it2;
            it2.nextElement();
        }
    }
}

void Controller::RemoveIfIn(bool in){
    List<Tranzactie>::iterator it2 = list.begin();
    List<Tranzactie>::iterator it1 = list.begin();
    int count = list.countElements();
    for (int i=0; i<count; i++){
        if (it2.getElement().in == in){
            if (checkEqual(it1.getElement(), it2.getElement())){
                list.removeFirst();
                it1 = list.begin();
                it2 = it1;
            }
            else{
                it1.getNode()->setNext(it2.getNode()->getNext());
                list.setCount(list.countElements()-1);
                it2 = it1;
                it2.nextElement();
            }
        }
        else{
            it1 = it2;
            it2.nextElement();
        }
    }
}

void Controller::RemoveFromList(unsigned int pos)
{
    List<Tranzactie>::iterator it1 = list.begin();
    List<Tranzactie>::iterator it2 = list.begin();
    it1.nextElement();

    if(pos >= (unsigned)list.countElements())
    {
        list.removeLast();
    }
    else
    {


        while(it1.hasNext())
        {
            if(pos == 1)
            {
                it2.setElement(it1.getElement());
                it1.nextElement();
                it2.nextElement();
            }
            else
            {
                pos--;
                it1.nextElement();
                it2.nextElement();
            }
        }

        it2.setElement(it1.getElement());
        list.removeLast();
    }

}

void Controller::RemoveFromList(unsigned int start, unsigned int end)
{
    int steps=end - start + 1;
    if(steps < 0) return ;
    while(steps-- != 0)
        RemoveFromList(start);
}

void Controller::RemoveFromList(List<Tranzactie>& list, unsigned int start, unsigned int end)
{
    int steps=end - start + 1;
    if(steps < 0) return ;
    while(steps-- != 0)
        RemoveFromList(start);
}

void Controller::ReplaceAll(List<Tranzactie>& subList, List<Tranzactie>& withList)
{
    List<Tranzactie>::iterator it1 = list.begin();
    List<Tranzactie>::iterator it2 = subList.begin();
    int duppCountList = list.countElements();
    int counter, i=0, j=0, found=0, countOcurrences=0;
    int* posArray = new int[(int)(list.countElements()/subList.countElements())+1];
    MakeIntArrayNull(posArray,(int)(list.countElements()/subList.countElements())+1);
    while(it1.hasNext())
    {
        j++;
        while(it2.hasNext())
        {
            if(checkEqual(it1.getElement(),it2.getElement()))
            {
                //found=j;
                counter++;
                j++;
                if(it1.hasNext())
                    it1.nextElement();
            }
            else counter=0;
            it2.nextElement();
        }
        // pentru ultimul el care nu e verificat in while
        if(checkEqual(it1.getElement(),it2.getElement()))
        {
            counter++;
            //if(subList.countElements()==1) found=j; //j++;
        }
        else counter=0;
        if(counter == subList.countElements()) // s-au gasit toate;
            // se retine pozitia unde au fost gasite
        {
            found=j-counter+1;
            posArray[i++] = found;
            counter=0;
        }
        //
        if(it1.hasNext())
        {
            it1.nextElement();
            it2 = subList.begin();
        }
    }
    if(++j == list.countElements())
    {
                while(it2.hasNext())
        {
            if(checkEqual(it1.getElement(),it2.getElement()))
            {
                //found=j;
                counter++;
                j++;
                if(it1.hasNext())
                    it1.nextElement();
            }
            else counter=0;
            it2.nextElement();
        }
        // pentru ultimul el care nu e verificat in while
        if(checkEqual(it1.getElement(),it2.getElement()))
        {
            counter++;
            //if(subList.countElements()==1) found=j; //j++;
        }
        else counter=0;
        if(counter == subList.countElements()) // s-au gasit toate;
            // se retine pozitia unde au fost gasite
        {
            found=j-counter+1;
            posArray[i++] = found;
            counter=0;
        }
        //
        if(it1.hasNext())
        {
            it1.nextElement();
            it2 = subList.begin();
        }
    }
    countOcurrences=i;
    it1 = withList.begin();
    j=0;
    counter =0;
    // am reusit sa iau pozitiile si sa le stochez intr-o lista
    for(i=0; i<countOcurrences; i++)
    {

            RemoveFromList(posArray[i]- counter, posArray[i]+ subList.countElements() - counter - 1);
        while(it1.hasNext())
        {
            AddToList(it1.getElement(),posArray[i]-counter--);
            it1.nextElement();
        }
        AddToList(it1.getElement(),posArray[i]-counter);
        counter = -
        list.countElements()+ duppCountList;//subList.countElements() - withList.countElements();
        //if(i+1 == countOcurrences)

        it1 = withList.begin();
    }
}

List<Tranzactie>& Controller::getGreaterThan(unsigned int amount){
    List<Tranzactie> listaNoua;
    List<Tranzactie>::iterator it = list.begin();
    for (int i=0; i<list.countElements(); i++){
        if (it.getElement().amount > amount)
            listaNoua.addLast(it.getElement());
        it.nextElement();
    }
    return listaNoua;
}

List<Tranzactie>& Controller::getLessThan(unsigned int amount){
    List<Tranzactie> listaNoua;
    List<Tranzactie>::iterator it = list.begin();
    for (int i=0; i<list.countElements(); i++){
        if (it.getElement().amount < amount)
            listaNoua.addLast(it.getElement());
        it.nextElement();
    }
    return listaNoua;
}

List<Tranzactie>& Controller::getType(bool type){
    List<Tranzactie> listaNoua;
    List<Tranzactie>::iterator it = list.begin();
    for (int i=0; i<list.countElements(); i++){
        if (it.getElement().in == type)
            listaNoua.addLast(it.getElement());
        it.nextElement();
    }
    return listaNoua;
}

List<Tranzactie>& Controller::getDayElements(unsigned int day){
    List<Tranzactie> listaNoua;
    List<Tranzactie>::iterator it = list.begin();
    for (int i=0; i<list.countElements(); i++){
        if (it.getElement().day == day)
            listaNoua.addLast(it.getElement());
        it.nextElement();
    }
    return listaNoua;
}

List<Tranzactie>& Controller::getElementsInOut(bool in){
    List<Tranzactie> listaNoua;
    List<Tranzactie>::iterator it = list.begin();
    for (int i=0; i<list.countElements(); i++){
        if (it.getElement().in == in)
            listaNoua.addLast(it.getElement());
        it.nextElement();
    }
    return listaNoua;
}


void Controller::FilterInOut(bool in){
    List<Tranzactie>::iterator it2 = list.begin();
    List<Tranzactie>::iterator it1 = list.begin();
    int count = list.countElements();
    for (int i=0; i<count; i++){
        if (it2.getElement().in == in){
            it1 = it2;
            it2.nextElement();

        }
        else{
            if (checkEqual(it1.getElement(), it2.getElement())){
                list.removeFirst();
                it1 = list.begin();
                it2 = it1;
            }
            else{
                it1.getNode()->setNext(it2.getNode()->getNext());
                list.setCount(list.countElements()-1);
                it2 = it1;
                it2.nextElement();
            }

        }
    }
}


void Controller::FilterGreater(bool in, float amount){
    List<Tranzactie>::iterator it2 = list.begin();
    List<Tranzactie>::iterator it1 = list.begin();
    int count = list.countElements();
    for (int i=0; i<count; i++){
        if (it2.getElement().in == in && it2.getElement().amount > amount ){
            it1 = it2;
            it2.nextElement();

        }
        else{
            if (checkEqual(it1.getElement(), it2.getElement()) ){
                list.removeFirst();
                it1 = list.begin();
                it2 = it1;
            }
            else{
                it1.getNode()->setNext(it2.getNode()->getNext());
                list.setCount(list.countElements()-1);
                it2 = it1;
                it2.nextElement();
            }

        }
    }
}



bool Controller::checkEqual(Tranzactie elem1, Tranzactie elem2){
    if (elem1.day != elem2.day)
        return false;
    if (elem1.description != elem2.description)
        return false;
    if (elem1.in != elem2.in)
        return false;
    return true;
}


void Controller::Undo()
{
    List<Tranzactie>::iterator it = list.begin();
            list.removeAll();

    // golesc lista
    //RemoveFromList(list,1,list.countElements());
      for(int i= 1; i<=listaVeche.countElements(); i++)
    {
        list.addLast(it.getElement());
        it.nextElement();
    }
}

void Controller::CopyList()
{

    List<Tranzactie>::iterator it1 = list.begin();
            listaVeche.removeAll();
    // golesc lista
    //RemoveFromList(listaVeche,1,listaVeche.countElements());
      for(int i= 1; i<=list.countElements(); i++)
    {
        listaVeche.addLast(it1.getElement());
        it1.nextElement();
    }
}
