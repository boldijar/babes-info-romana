#ifndef RATIONAL_H_
#define RATIONAL_H_

/*
 * Represents a rational number
 */
struct rational {
	int m; //nominator
	int n; //denominator
};

typedef struct rational Rational;

/*
 * Add b to a - operation on rational numbers ("a = a + b")
 */
void add(Rational* a, Rational b);

/*
 * Initialize a rational number
 */
void init(Rational* r, int m, int n);

#endif /* Q_H_ */
