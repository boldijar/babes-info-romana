/*
 * ContainerRepository.h
 *
 *  Created on: Jun 7, 2012
 *      Author: Admin
 */

#ifndef CONTAINERREPOSITORY_H_
#define CONTAINERREPOSITORY_H_
#include "../Utils/TADMultime.h"
#include "../Domain/Container.h"

class ContainerRepository {
public:
	void add(Container cnt);
	void remove(Container cnt);
	bool search(Container cnt);
	int size();
	Multime<Container>* getMul() {
		return &mul;
	}
private:
	Multime<Container> mul;
};



#endif /* CONTAINERREPOSITORY_H_ */
