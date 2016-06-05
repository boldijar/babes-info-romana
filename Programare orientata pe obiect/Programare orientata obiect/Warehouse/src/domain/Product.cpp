/*
 * Product.cpp
 *
 *  Created on: 2012-04-03
 *      Author: istvan
 */

#include "Product.h"
#include <string>
using namespace std;
Product::Product() {
	code = -1;
	desc = "";
	price = 0;
}
Product::Product(int c, string d, double p) {
	code = c;
	desc = d;
	price = p;
}

