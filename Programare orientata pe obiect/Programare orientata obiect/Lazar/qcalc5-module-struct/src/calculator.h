/*
 * calculator.h
 *
 *  Created on: 6 Mar 2012
 *      Author: ilazar
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "rational.h"

struct calculator {
	Rational total;
};

typedef struct calculator Calculator;

void reset(Calculator* c);
void add_number(Calculator* c, Rational r);
Rational get_total(Calculator* c);

#endif /* CALCULATOR_H_ */
