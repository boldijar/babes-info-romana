#include "StdAfx.h"
#include "Except.h"

std::string msg;
Except::Except(const std::string m="exception!") throw() : msg(m){}
const char * Except::what() throw() {return msg.c_str();}


Except::~Except(void)
{
}
