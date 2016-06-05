#include "StdAfx.h"
#include "ValidatorClass.h"
#include <assert.h>
#include "Except.h"
#include <fstream>
using namespace std;

ValidatorClass::ValidatorClass(void)
{
}

void ValidatorClass::validareId(int id){
	if(this->validId(id) == false)
		throw Except("Id-ul este necorespunzator");
}

void ValidatorClass::validareNumar(int number){	
	if(this->validNumar(number) == false)
		throw Except("Numarul dat este necorespunzator");
}

void ValidatorClass::validareSuma(float amount){
	if(this->validSuma(amount) == false)
		throw Except("Suma data este necorespunzatoare");
}

void ValidatorClass::testValidatori(){
	ValidatorClass val;
}

ValidatorClass::~ValidatorClass(void)
{
}
