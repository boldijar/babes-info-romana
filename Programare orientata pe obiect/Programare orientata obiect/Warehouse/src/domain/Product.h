/*
 * Product.h
 *
 *  Created on: 2012-04-03
 *      Author: istvan
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <string>
using namespace std;

/**
 * Model the products from the warehouse
 * (code, price, descriprion)
 */
class Product {
public:

	/**
	 * Constructor, intialise the product
	 * c - unique code
	 * d - description of the product
	 * p - price of the product
	 */
	Product(int c, string d, double p);
	Product();
	/**
	 * getter for the code
	 */
	int getCode() const {
		return code;
	}
	/**
	 * getter for the description
	 */
	const string& getDescription() const {
		return desc;
	}
	/**
	 * getter for the price
	 */
	double getPrice() const {
		return price;
	}

private:
	int code;
	string desc;
	double price;
};

#endif /* PRODUCT_H_ */
