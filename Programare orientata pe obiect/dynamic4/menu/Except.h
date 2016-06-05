#pragma once
#include <exception>
#include <string>

class Except:public std::exception{
public:
	//exception;
	//std::string alor;
	//const char* msg;
	const char * what();
	Except(const std::string m);
	
	~Except(void);
private:
	const std::string msg;
};

