#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex{
	public:
		Complex(double,double);
		Complex();
		Complex(const Complex&);
		Complex operator+(Complex);
		Complex operator-(Complex);
		Complex operator*(Complex);
		Complex operator/(Complex);
		
		void operator=(const Complex&);
		void operator=(double);
		
		bool operator==(Complex);
		bool operator!=(Complex);
		
		friend std::ostream& operator<<(std::ostream& os, Complex& r);
		friend std::istream& operator>>(std::istream& is, Complex& r);
	private:
		double r,i;
};

#endif
