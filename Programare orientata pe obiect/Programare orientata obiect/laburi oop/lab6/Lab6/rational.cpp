#include "rational.h"

int Rational::gcd(int a,int b){
	int aux;
	while(b){
		aux = a%b;
		a=b;
		b=aux;
	}
	return a;
}

void Rational::simplify(){
	int aux = gcd(n,d);
	d/=aux;
	n/=aux;
}

Rational::Rational(){
	d=0;
	n=1;
}

Rational::Rational(int d,int n){
	this->d = d;
	this->n = n;
}
		
Rational Rational::operator+(Rational x){
	Rational ret(x.n*d+x.d*n,x.n*n);
	ret.simplify();
	return ret; 
}

Rational Rational::operator-(Rational x){
	Rational ret(x.n*d-x.d*n,x.n*n);
	ret.simplify();
	return ret; 
}

Rational Rational::operator/(Rational x){
	Rational ret(x.d*n,x.n*d);
	ret.simplify();
	return ret; 
}

Rational Rational::operator*(Rational x){
	Rational ret(x.d*d,x.n*n);
	ret.simplify();
	return ret; 
}


Rational Rational::operator=(Rational x){
	n = x.n;
	d = x.d;
}
		
bool Rational::operator==(Rational x){
	return d==x.d && n==x.n;
}
bool Rational::operator<(Rational x){
	return x.d*n>x.n*d;
}
bool Rational::operator>(Rational x){
	return x.d*n<x.n*d;
}
bool Rational::operator<=(Rational x){
	return x.d*n>=x.n*d;
}
bool Rational::operator>=(Rational x){
	return x.d*n<=x.n*d;
}
		
float Rational::eval(){
	return (float)d/n;
}

std::ostream& operator<<(std::ostream& os, Rational& r){
	os<<r.d;
	if(r.n!=1)
		os<<'/'<<r.n;
	
	return os;
}
std::istream& operator>>(std::istream& is, Rational& r){
	is>>r.d;
	if(is.peek() == '/'){
		is.get();
		is>>r.n;
	}
	
	return is;
}
