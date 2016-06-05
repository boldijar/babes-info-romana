/*
 ============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ui.h"

#include "repository.h"
int main(void) {
	Repo* repo = malloc(sizeof(Repo));
	repo->file_name = malloc(sizeof(char) * (strlen("car_pool.txt")+1));//

	strcpy(repo->file_name,"car_pool.txt");//
	load_meniu(repo);



	/*
	Car* car = malloc(sizeof(Car));
	car->categorie = malloc(sizeof(char) * (strlen("SUV")+1));
	strcpy(car->categorie, "SUV");

	Repo* repo = malloc(sizeof(Repo));
	repo->lista[0] = malloc(sizeof(car));
	repo->lista[0] = car;
	printf("%s",repo->lista[0]->categorie);
	*/

	//scanf("%d",i);
	free(repo->file_name);
	free(repo);
	return EXIT_SUCCESS;
}

