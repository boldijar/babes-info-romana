/*
 * ContainerController.h
 *
 *  Created on: Jun 7, 2012
 *      Author: Admin
 */

#ifndef CONTAINERCONTROLLER_H_
#define CONTAINERCONTROLLER_H_

#include "../Repository/ContainerRepository.h"
#include <string>
using namespace std;

class ContainerController {
public:
	ContainerController(ContainerRepository* repo) : repo(repo) {}
	void add(string cnp);
	void remove(string cnp);
	bool search(string cnp);
	int size();
	Multime<Container>* getMul() {
		return repo->getMul();
	}
private:
	ContainerRepository* repo;
};


#endif /* CONTAINERCONTROLLER_H_ */
