#include "rational.h"
#include <iostream>
#include <assert.h>

using namespace std;

void Q::println(const char* text) {
	std::cout << text;
	std::cout << " m = " << m << " n = " << n;
	std::cout << std::endl;
}

void Q::init(int m, int n) {
	assert(n != 0);
	this->m = m;
	this->n = n;
}

Q::Q() {
	init(0, 1);
	println("Q()");
}

Q::Q(int m) {
	init(m, 1);
	println("Q(int)");
}

Q::Q(int m, int n) {
	init(m, n);
	println("Q(int, int)");
}

Q::Q(const Q& other) {
	init(other.m, other.n);
	println("Q(Q&)");
}

Q::~Q() {
	println("~Q()");
}

Q& Q::add(const Q& other) {
	m = m * other.n + n * other.m;
	n = n * other.n;
	println("add(Q&)");
	return *this;
}

Q operator+(Q& a, Q& b) {
	Q c = a;
	return c.add(b);
}
