/*
 * Container.h
 *
 *  Created on: Jun 7, 2012
 *      Author: Admin
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <string>
using namespace std;

class Container {
public:
	Container(string cnp) : cnp(cnp) {}
	Container() : cnp("") {}
	string getCnp() {
		return cnp;
	}
	int hashCode()
		{
			int sum = 0;
			for(unsigned i = 0; i < str.length(); i++)
				sum += str[i];
		    return sum;
		}
	bool operator == (Container& other) {
		return cnp == other.getCnp();
	}

private:
	string cnp;
	string str;
};



#endif /* CONTAINER_H_ */
