#include "StdAfx.h"
#include "ValidatorClass.h"
#include <assert.h>
#include "Except.h"
#include <fstream>
using namespace std;

ValidatorClass::ValidatorClass(void)
{
}

void ValidatorClass::validareId(int number){
	if(number <= 0 || number > 4000)
		throw Except("Id-ul este necorespunzator");
	
}
void ValidatorClass::validareNumar(int number){
	if(number <= 0 || number > 50)
		throw Except("Numarul dat este necorespunzator");
}

void ValidatorClass::validareSuma(float amount){
	if(amount > 2000 || amount == 0)
		throw Except("Suma data este necorespunzatoare");
}

void ValidatorClass::testValidatori(){
	ValidatorClass val;

	
}
ValidatorClass::~ValidatorClass(void)
{
}
