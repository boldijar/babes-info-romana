/*
 * repository.h
 *
 *  Created on: Mar 4, 2015
 *      Author: andrei
 */

#ifndef REPOSITORY_H_
#define REPOSITORY_H_
#include "domain.h"

struct repo{
	Car* lista[25];///pt returnare masini
	char* file_name;

};

typedef struct repo Repo;

void add_repo(Repo* repo,Car* car);
Car* repo_get_cars(Repo* repo);
Car* build_car(char *line);
void add_car_to_repo_list(Repo* repo, Car* car);
int length(Car *array);



#endif /* REPOSITORY_H_ */
