#ifndef PRIORITY_QUEUE_H_INCLUDED
#define PRIORITY_QUEUE_H_INCLUDED


#include "elevi.h"
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;
using namespace domain;
namespace prq {

class PrQueue
{
    int size ;
    int currentIndex;

public:
    PrQueue(){size = 0;}
    ~PrQueue(){};
    Elev v[100];
    int next_Elem[100];


    Elev pop()
    {

        if (size > 0) {
            int current = currentIndex;
            currentIndex = next_Elem[currentIndex ];
            if (current < currentIndex) {
                currentIndex--;
            }
            Elev e = v[current];
            for (int i = current; i < size; i++) {
                v[i] = v[i + 1];
                next_Elem[i] = next_Elem[i + 1];
            }
            for (int i = 1; i <= size; i++) {
                if (next_Elem[i] >= current) {
                    next_Elem[i]--;
                }
            }
            size--;
            return e;
        }

    }

    Elev element()
    {

        //return the most priority student
        int current = currentIndex;
        Elev e = v[current];
        return e;

    }
    void add( Elev e )
    {

        int prev = 0;
        int next;
        int current = currentIndex;
        if (size == 0) {
            size++;
            v[size] = e;
            next_Elem[size] = -1;
            currentIndex = size;
            return;
        }
        if (v[currentIndex].getPriority() < e.getPriority()) {
            size++;
            v[size] = e;
            next_Elem[size] = currentIndex;
            currentIndex = size;
            return;
        }

        while (current != -1 && v[current].getPriority() >= e.getPriority()) {
            prev = current;
            current = next_Elem[current];
        }
        if (current != -1) {
            next = current;
            size++;
            v[size] = e;
            next_Elem[size] = next;
            next_Elem[prev] = size;
        } else {

            size++;
            v[size] = e;
            next_Elem[prev] = size;
            next_Elem[size] = -1;
        }
      //  currentIndex = size;

    }
    int Size()
    {
        return size;
    }
    int curentIndex()
    {

        return currentIndex;
    }

    int Plina()
    {

        if( size == 100 )
            return 1;
        else
            return 0;
    }



};

}

#endif // PRIORITY_QUEUE_H_INCLUDED
