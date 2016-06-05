#include "Integer.h"


Integer::Integer()
{
	value = 0;
}

Integer::Integer(const Integer& aux)
{
	value = aux.value;
}

Integer::Integer(int aux)
{
	value = aux;
}

char* Integer::toString()
{
	char* buf = new char[15];
	sprintf(buf,"%d",value);
	return buf;
}

int Integer::getValue()
{
	return value;
}

void Integer::setValue(int a)
{
	value = a;
}

int Integer::comparesTo(IElem* aux)
{
	Integer* Int = (Integer*)aux;
	if (this->value < Int->value)
		return -1;
	if (this->value == Int->value)
		return 0;
	return 1;
}

void Integer::print()
{
	std::cout << this->value << " ";
}

ostream& Integer::operator<<(ostream& stream)
{
  stream<<this->value;
  return stream;
}

istream& Integer::operator>>(istream& stream)
{
  stream>>this->value;
  return stream;
}


Integer::~Integer()
{
}
