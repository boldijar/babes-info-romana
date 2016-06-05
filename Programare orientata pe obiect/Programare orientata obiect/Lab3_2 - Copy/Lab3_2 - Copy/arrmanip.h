#ifndef ARRMANIP_H_INCLUDED
#define ARRMANIP_H_INCLUDED
#include <sstream>
#include "Node.h"
#include<string>

using namespace std;

template<typename Element> class List;
template<typename Element> class Iterator;

struct Tranzactie{
            int day;
            float amount;
            bool in;
            string description;};



template<typename Element>
class Iterator
{
    friend class List<Element>;

private:
    Node<Element>* current;
    Iterator(Node<Element>* newCurrent)
    {
        current=newCurrent;
    }
public:
    void nextElement()
    {
        if (current!=0)
            current=current->getNext();
    }

    Node<Element>* getNode(){
        return current;
    }

    int hasNext()
    {
        if (current!=0)
        {
            if (current->getNext()!=0)
                return 1;
            else return 0;
        }
        return 0;
    }
    Element getElement()
    {
        return this->current->getElement();
    }

    void setElement(Element e)
    {
        this->current->setElement(e);
    }
};

template<typename Element>
class List // type : LIFO
{
private:
    Node<Element>* head;
protected:
    int count;
public:
    typedef Iterator<Element> iterator;
    List()
    {
        head=0;
        count=0;
    }

    Iterator<Element> begin()
    {
        return *(new Iterator<Element>(head));
    }

    void setCount(int count){
        this->count = count;
    }

    void addLast(Element e)
    {
        if (head==0)
        {
            Node<Element>* node=new Node<Element>(e, 0);
            head=node;
            count++;
        }
        else
        {
            Node<Element>* p=head;
            while (p->getNext()!=0)
                p=p->getNext();
            p->setNext(new Node<Element>(e,0));
            count++;
        }
    }

    int countElements()
    {
        return count;
    }

    void removeFirst(){
        if (head != 0){
            Node<Element>* p = head;
            Node<Element>* q = p->getNext();
            delete p;
            this->head = q;
            count--;
        }
    }

    void removeAll(){
       head = 0;
       count = 0;
    }

    void removeLast()
    {
        if(head != 0)
        {
            Node<Element>* p=head;
            for(int i=1; i< count-1; i++)
                if(p->getNext()!=0) // in mod normal are trebuie sa fie mereu adevarat, dar il pun ca sa fim siguri
                    p=p->getNext();
            //delete p;//->setNext(0);
            p->setNext(0);
            delete p->getNext();
            //p->setNext(new Node<double>(0,0));
            count--;

        }
    }

};


#endif // ARRMANIP_H_INCLUDED
