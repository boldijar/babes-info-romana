/*
 * ContainerRepository.cpp
 *
 *  Created on: Jun 7, 2012
 *      Author: Admin
 */
#include "../utils/TADMultime.h"
#include "../utils/String.h"
#include "ContainerRepository.h"

void ContainerRepository::add(Container cnt) {
	mul.add(cnt);
}

void ContainerRepository::remove(Container cnt) {
	mul.remove(cnt);
}

bool ContainerRepository::search(Container cnt) {
	return mul.search(cnt);
}

int ContainerRepository::size() {
	return mul.size();
}


