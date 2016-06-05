/*
 * service.h
 *
 *  Created on: Mar 4, 2015
 *      Author: andrei
 */

#ifndef SERVICE_H_
#define SERVICE_H_
#include "repository.h"

void create_car(Repo* repo, char licenta[], char model[], char categorie[]);
Car* get_cars(Repo* repo);

#endif /* SERVICE_H_ */
