/*
 * repository.c
 *
 *  Created on: Mar 4, 2015
 *      Author: andrei
 */

#include<stdio.h>
#include "domain.h"
#include "repository.h"

void add_repo(Repo* repo, Car* car) {

	FILE *ptr_file;
	ptr_file = fopen(repo->file_name, "a");

	if (!ptr_file)
		return;

	fprintf(ptr_file, "%s*_*%s*_*%s*_*%d\n", car->licenta, car->model,
			car->categorie, car->inchiriat);
	//printf("%s",car->licenta);

	fclose(ptr_file);
}

Car* repo_get_cars(Repo* repo) {
	char line[256];
	FILE *ptr_file;
	ptr_file = fopen(repo->file_name, "r");

	if (!ptr_file)
		return NULL;

	while (fgets(line, sizeof(line), repo->file_name)) {
		Car* car = build_car(line);
		add_car_to_repo_list(repo, car);
	}
	fclose(ptr_file);

	return repo->lista;
}

Car* build_car(char *line) {
	char *p;
	p = strtok(line, "*_*");

	Car* car;
	car->licenta = p[0];
	car->model = p[1];
	car->categorie = p[2];
	car->inchiriat = p[3];

	return car;
}

void add_car_to_repo_list(Repo* repo, Car* car) {
	int v = length(repo->lista);
	repo->lista[v] = car;
}

int length(Car *array) {
/*	int count = 0;
	while (array[count]) {
		count++;
	}
	return count;*/
	return sizeof(array) / sizeof(array[0]);
}
