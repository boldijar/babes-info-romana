#include "StdAfx.h"
#include "BoolValidator.h"
#include <assert.h>

BoolValidator::BoolValidator(void)
{
}

bool BoolValidator::validId(int id){
	if(id <= 0 || id > 4000)
		return false;
	return true;
}

bool BoolValidator::validNumar(int number){
	if(number <= 0 || number > 50)
		return false;
	return true;
}

bool BoolValidator::validSuma(float amount){
	if(amount > 2000 || amount == 0)
		return false;
	return true;
}

void BoolValidator::testValidatori(){
	BoolValidator val;
	assert(val.validNumar(10)==true);
	assert(val.validId(10)==true);
}

BoolValidator::~BoolValidator(void)
{
}
