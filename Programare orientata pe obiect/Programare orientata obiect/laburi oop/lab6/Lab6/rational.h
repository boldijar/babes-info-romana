#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational{
	public:
		Rational();
		Rational(int,int);
		
		Rational operator+(Rational);
		Rational operator-(Rational);
		Rational operator/(Rational);
		Rational operator*(Rational);
		
		Rational operator=(Rational);
		
		bool operator==(Rational);
		bool operator>(Rational);
		bool operator<(Rational);
		bool operator>=(Rational);
		bool operator<=(Rational);
		
		float eval();
	private:	
		int gcd(int,int);
		void simplify();
		int d,n;
		
		friend std::ostream& operator<<(std::ostream& os, Rational& r);
		friend std::istream& operator>>(std::istream& os, Rational& r);
};

std::ostream& operator<<(std::ostream& os, Rational& r);
std::istream& operator>>(std::istream& os, Rational& r);

#endif
