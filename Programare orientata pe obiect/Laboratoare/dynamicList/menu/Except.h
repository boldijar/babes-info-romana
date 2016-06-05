#pragma once
#include <exception>
#include <string>

class Except:public std::exception{
public:
	const char * what();
	Except(const std::string m);
	
	~Except(void);
private:
	const std::string msg;
};

