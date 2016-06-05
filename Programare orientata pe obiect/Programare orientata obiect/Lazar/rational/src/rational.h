/*
 * rational.h
 *
 *  Created on: 13 Mar 2012
 *      Author: ilazar
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

class Q {
private:
	int m;
	int n;
	void init(int m, int n);
	void println(const char*);
public:
	Q();
	Q(int m);
	Q(int m, int n);
	Q(const Q& other);
	~Q();
	int get_nominator() const {
		return m;
	}
	int get_denominator() const {
		return n;
	}
	Q& add(const Q& other);
};

Q operator+(Q& a, Q& b);

#endif /* RATIONAL_H_ */
