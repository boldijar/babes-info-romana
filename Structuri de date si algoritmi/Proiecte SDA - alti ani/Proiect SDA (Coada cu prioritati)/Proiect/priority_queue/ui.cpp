

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#include "ui.h"
#include "repository.h"

using namespace repository;

namespace ui
{

    Console::Console(Repo* r)
    {
            this->repo = r;
    }

    Console::~Console()
    {

    }

    void Console::printMenu()
    {
        cout << '\n';
        cout << '\n';
        cout << "Student grant application " << '\n' ;
        cout << '\n';
        cout << "A) Adauga un student in lista burselor " << '\n';
        cout << "D) Sterge studentul cel mai prioritar " << '\n';
        cout << "S) Afiseaza primii k studenti in ordinea mediilor " << '\n';
        cout << "F) Afiseaza cel mai bun student " << '\n';
        cout << "X) Exit" << '\n';

        cout << '\n';
        cout << '\n';
    }

    void Console::run()
    {


        int ok=1;
        while (ok)
        {
		printMenu();
		cout <<"Dati optiunea dumneavoastra";
		cout << '\n';

		char opt;
		cin >> opt;
		cin.get();

		if ( opt == 'A' )
		{
			add();

		}
		else
			if ( opt == 'D' )
			{

				pop();

			}
			else
				if ( opt == 'S')
                {
                    cout << " Introdu numarul de studenti pe care vrei sa-i afisezi " << '\n';
                    int k;
                    cin >> k;
                    if( k > repo->getSize() )
                        cout << " Nu exista in lista atatia studenti!! " << '\n';
                    else
                    {
                        system("CLS");
                        repo->getAll2(k);

                    }
                   // cout << k << '\n';

                }
                else
                    if( opt == 'F' )
                {
                    if( repo->getSize() > 0 )
                    element();
                    else
                        cout << " In lista nu exista nici un student " << '\n';
                }
                else
                    if( opt == 'X' )
                        break;
				else
                    cout << " Invalid option " << '\n';


	}
    }

    void Console::add()
    {

        string nume , prenume;
        float medie;
        cout << " Introdu numele studentului " << '\n';
        cin >> nume ;
        cout << " Introdu prenumele studentului " << '\n';
        cin >> prenume ;
        cout << " Introdu media studentului( 0-2 zecimale ); " << '\n';
        cin >> medie;

        cout << '\n';
        cout << '\n';
        cout << '\n';

        Elev x(nume,prenume,medie);
        system("CLS");
        repo->add(x);
        repo->getAll();


    }

    Elev Console::pop()
    {
        if ( repo->getSize() > 0 )
        {

        system("CLS");
        Elev x = repo->pop();
        repo->getAll();
        return x;

        }
        else
            cout << " Nu avem un student prioritar!!! " << '\n';

    }

    Elev Console::element()
    {
        system("CLS");
        Elev x = repo->element();

        cout << " Studentul cu cea mai mare medie este: " << '\n';
        cout << x.getNume() << " " << x.getPrenume() << " " << x.getPriority() << '\n';
        return x;

    }
}
