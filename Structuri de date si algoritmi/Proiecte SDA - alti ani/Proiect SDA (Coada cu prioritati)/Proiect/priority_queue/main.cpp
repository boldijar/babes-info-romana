
#include <iostream>
#include "elevi.h"
#include "priority_queue.h"
#include "repository.h"
#include <cstdlib>
#include "ui.h"

using namespace std;
using namespace domain;
using namespace prq;
using namespace repository;
using namespace ui;

int main()
{

    Repo* repo = new Repo();
    Console* c = new Console(repo);

    c->run();
    delete c;
    delete repo;

    system("pause");

    return 0;
}
