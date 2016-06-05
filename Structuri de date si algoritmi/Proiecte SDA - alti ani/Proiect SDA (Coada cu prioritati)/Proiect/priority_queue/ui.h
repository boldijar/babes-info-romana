#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#include "repository.h"

namespace ui
{

    class Console
    {

        repository::Repo* repo;

    public:
        Console(repository::Repo*);
        virtual ~Console();
        void printMenu();
        void run();
        void add();
        Elev pop();
        Elev element();

    };

}

#endif // UI_H_INCLUDED
