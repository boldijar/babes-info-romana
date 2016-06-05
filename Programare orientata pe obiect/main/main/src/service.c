/*
 * service.c
 *
 *  Created on: Mar 4, 2015
 *      Author: andrei
 */

#include "repository.h"
#include <string.h>
#include <malloc.h>

void create_car(Repo* repo, char licenta[], char model[], char categorie[],
		int inchiriat) {

	Car* car = malloc(sizeof(Car));

	car->licenta = malloc(sizeof(char) * (strlen(licenta) + 1)); //(*car).licenta
	strcpy(car->licenta, licenta);

	car->model = malloc(sizeof(char) * (strlen(model) + 1));
	strcpy(car->model, model);

	car->categorie = malloc(sizeof(char) * (strlen(categorie) + 1));
	strcpy(car->categorie, categorie);

	car->inchiriat = malloc(sizeof(int));
	car->inchiriat = inchiriat;
	//printf("%s",car->licenta);

	add_repo(repo, car);

	//free???

}

Car* get_cars(Repo* repo) {
	return repo_get_cars(repo);
}

int lungime_sir(Car* cars) {
/*	int count = 0;
	while (cars[count])
		count++;
	return count;*/
	return sizeof(cars) / sizeof(cars[0]);
}

