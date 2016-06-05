/*
 * ContainerController.cpp
 *
 *  Created on: Jun 7, 2012
 *      Author: Admin
 */


#include "ContainerController.h"
#include "../Domain/Container.h"

void ContainerController::add(string cnp) {
	Container cnt(cnp);
	repo->add(cnt);
}

void ContainerController::remove(string cnp) {
	Container cnt(cnp);
	repo->remove(cnt);
}

bool ContainerController::search(string cnp) {
	Container cnt(cnp);
	return repo->search(cnt);
}

int ContainerController::size() {
	return repo->size();
}
