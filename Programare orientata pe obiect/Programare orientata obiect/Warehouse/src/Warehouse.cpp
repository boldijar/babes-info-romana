//============================================================================
// Name        : Warehouse.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "domain/testProduct.h"
#include "repository/testInMemoryRepo.h"
#include "controller/testController.h"
#include "ui/ConsoleUI.h"
using namespace std;

void testApp() {
	//Functionality - add a product
	testCreateProduct(); //Task 1
	testStoreInMemory(); //Task 2
	testGetByIdInMemory(); //Task 3
	testStoreExceptionInMemory(); //Task 3

	testValidateProduct(); //Task 4
	testAdd(); // Task 5

}

void startApp() {
	//create validator
	ProductValidator* val = new ProductValidator();
	//create reporsitory
	ProductRepository* repo = new ProductInMemoryRepository();
	//create controller
	Warehouse wh(repo, val);
	//create ui
	ConsoleUI ui(&wh);
	//start ui
	ui.showUI();
}
int main() {
	testApp();
	startApp();
	return 0;
}
