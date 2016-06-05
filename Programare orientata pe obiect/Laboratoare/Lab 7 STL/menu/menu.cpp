// meniu.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "string.h"
#include <iostream>
#include "MenuClass.h"
#include "DomainClass.h"
#include "RepositoryClass.h"
#include "ControllerClass.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[]){
	MenuClass* meniu = new MenuClass();
	meniu->ruleazaMeniu();
	return 0;
}
