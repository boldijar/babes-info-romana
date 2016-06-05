#pragma once
#include "BoolValidator.h"

class ValidatorClass:BoolValidator
{
public:
	ValidatorClass(void);
	void validareId(int);
	void validareNumar(int);
	void validareSuma(float);
	void testValidatori();
	~ValidatorClass(void);
};

