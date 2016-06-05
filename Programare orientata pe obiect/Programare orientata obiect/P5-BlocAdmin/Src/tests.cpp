/*
 * tests.cpp
 *
 *  Created on: 24.03.2012
 *      Author: Florin Mihalache
 */
#include <assert.h>
#include <iostream>
#include "alist.h"
#include "ui.h"
#include "tests.h"
using namespace std;

void testInsertion(){
	aptList apts;
	apts.insert(23, "water", 150);
	apts.insert(4, "water", 154);
	apts.insert(23, "heating", 200.16);

	assert(apts.aSize == 2);
	assert(apts.aList[0].eList[1].amount == (float) 200.16);
	assert(apts.aList[0].eList[1].type == "heating");
	assert(apts.aList[1].eList[0].amount == 154);
	assert(apts.aList[1].eList[0].type == "water");
}

void testRemove() {
	aptList apts;
	apts.insert(2, "water", 150);
	apts.insert(4, "water", 154);
	apts.insert(2, "heating", 200.16);
	apts.insert(4, "water", 200.16);
	apts.insert(6, "heating", 443);
	apts.insert(7, "gas", 223);
	apts.insert(7, "heating", 200.126);

	Apartment* apt;
	apt = apts.getAptByNumber(2);
	assert(apt->eSize == 2);
	apts.remove(2);
	assert(apt->eSize == 0);

	apts.remove(4, 7);
	assert(apts.getAptByNumber(4)->eSize == 0);
	assert(apts.getAptByNumber(6)->eSize == 0);
	assert(apts.getAptByNumber(7)->eSize == 0);

	// remove by type
	apts.insert(2, "water", 150);
	apts.insert(4, "water", 154);
	apts.insert(2, "heating", 200.16);
	apts.insert(4, "water", 200.16);
	apts.insert(6, "heating", 443);
	apts.insert(7, "gas", 223);
	apts.insert(2, "water", 200.126);

	assert(apts.getAptByNumber(2)->eSize == 3);
	apts.removeAllByType("water");
	assert(apts.getAptByNumber(2)->eSize == 1);
	assert(apts.getAptByNumber(2)->eList[0].type == "heating"); // remaining expense after the last remove by type
	assert(apts.getAptByNumber(4)->eSize == 0);
}

void testWritingProperties() {
	aptList apts;
	apts.insert(1, "water", 50);
	apts.insert(1, "gas", 120);
	apts.insert(2, "heating", 100);
	apts.insert(3, "water", 80);
	apts.insert(3, "water", 100.66);
	apts.insert(4, "gas", 50);
	apts.insert(4, "water", 60);
//	writeGreaterThan(apts, 150);
//	writeGreaterThan(apts, 100);
//	writeGreaterThan(apts, 200);
//	writeLessThan(apts, 200, 2);
//	writeLessThan(apts, 50, 3);
//	writeLessThan(apts, 150, 4);
//	writeAllType(apts, "water");
//	writeAllType(apts, "milk");
//	writeSold(apts, 1);
//	writeSold(apts, 2);
//	writeSold(apts, 3);
//	writeSumType(apts, "water");
//	writeSumType(apts, "gas");
//	apts.insert(3, "gas", 334);
//	apts.insert(3, "heating", 140);
//	apts.insert(3, "gas", 223);
//	writeMaxType(apts, 3);
}

void testSorting() {
	aptList apts;
	apts.insert(1, "water", 50);
	apts.insert(1, "gas", 120);
	apts.insert(1, "heating", 100);
	apts.insert(1, "water", 105);

	Apartment* apt = apts.getAptByNumber(1);
	apt->sort();
	assert(apt->eList[0].type == "water" && apt->eList[0].amount == 50);
	assert(apt->eList[1].type == "heating" && apt->eList[1].amount == 100);
	assert(apt->eList[2].type == "water" && apt->eList[2].amount == 105);
	assert(apt->eList[3].type == "gas" && apt->eList[3].amount == 120);
}

void testFilterByType() {
	aptList apts;
	apts.insert(1, "water", 50);
	apts.insert(1, "gas", 120);
	apts.insert(2, "heating", 100);
	apts.insert(3, "water", 80);
	apts.insert(3, "water", 100.66);
	apts.insert(3, "gas", 50);

	assert(apts.getAptByNumber(1)->eSize == 2);
	assert(apts.getAptByNumber(2)->eSize == 1);
	assert(apts.getAptByNumber(3)->eSize == 3);

	apts.filterByType("water");
	assert(apts.getAptByNumber(1)->eSize == 1);
	assert(apts.getAptByNumber(1)->eList[0].type == "water");
	assert(apts.getAptByNumber(2)->eSize == 0);
	assert(apts.getAptByNumber(3)->eSize == 2);
	assert(apts.getAptByNumber(3)->eList[0].type == "water");
	assert(apts.getAptByNumber(3)->eList[1].type == "water");

}

void testFilterGreaterThan() {
	aptList apts;
	apts.insert(1, "water", 50);
	apts.insert(1, "gas", 350);
	apts.insert(2, "heating", 100);
	apts.insert(3, "water", 310);
	apts.insert(3, "water", 442.43);
	apts.insert(3, "gas", 50);

	assert(apts.getAptByNumber(1)->eSize == 2);
	assert(apts.getAptByNumber(2)->eSize == 1);
	assert(apts.getAptByNumber(3)->eSize == 3);

	apts.filterGreaterThan(300);
	assert(apts.getAptByNumber(1)->eSize == 1);
	assert(apts.getAptByNumber(1)->eList[0].amount == 350);
	assert(apts.getAptByNumber(2)->eSize == 0);
	assert(apts.getAptByNumber(3)->eSize == 2);
	assert(apts.getAptByNumber(3)->eList[0].amount == 310);
	assert(apts.getAptByNumber(3)->eList[1].amount == (float) 442.43);
}

void testAll() {
	testInsertion();
	testRemove();
	//testWritingProperties();
	testSorting();
	testFilterByType();
	testFilterGreaterThan();
}




