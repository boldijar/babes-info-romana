#ifndef REPOSITORY_H_INCLUDED
#define REPOSITORY_H_INCLUDED

#include "elevi.h"
#include <string>
#include "priority_queue.h"

using namespace domain;
using namespace prq;

namespace repository
{

    class Repo
    {


public:
    PrQueue pr_queue;

    Repo(){}
    ~Repo(){}

    void add( domain::Elev x )
    {
        pr_queue.add(x);
    }
    Elev pop()
    {
        domain::Elev x = pr_queue.pop();
        return x;

    }

    Elev element()
    {

        domain::Elev x = pr_queue.element();
        return x;

    }

    int getSize()
    {

        int siz = pr_queue.Size();

        return siz;
    }


    void getAll()
    {

        int current = pr_queue.curentIndex();
         while( current != -1 )
        {

        cout << pr_queue.v[current].getNume() <<  " " << pr_queue.v[current].getPrenume() << " " << pr_queue.v[current].getPriority() << '\n';
        current = pr_queue.next_Elem[current];
        }
    }

    void getAll2( int &k )
    {
        int current = pr_queue.curentIndex();
        int rz = 1;
        while( current != -1 && rz <= k )
        {
        ++rz;
        cout << pr_queue.v[current].getNume() <<  " " << pr_queue.v[current].getPrenume() << " " << pr_queue.v[current].getPriority() << '\n';
        current = pr_queue.next_Elem[current];
        }

    }

    };


}


#endif // REPOSITORY_H_INCLUDED
