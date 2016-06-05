/*
 * app.cpp
 *
 *  Created on: 24.03.2012
 *      Author: Florin Mihalache
 */
#include <iostream>
#include "alist.h"
#include "ui.h"
#include "tests.h"

using namespace std;

int main() {
	testAll();
	aptList apts;
//	apts.insert(1, "water", 50);
//	apts.insert(1, "gas", 350);
//	apts.insert(2, "heating", 100);
//	apts.insert(3, "water", 310);
//	apts.insert(3, "water", 442.43);
//	apts.insert(3, "gas", 50);
	menu(&apts);

	return 0;
}
