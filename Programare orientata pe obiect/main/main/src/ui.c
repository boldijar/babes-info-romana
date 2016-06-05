/*
 * ui.c
 *
 *  Created on: Mar 3, 2015
 *      Author: andrei
 */

#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "service.h"
#include <string.h>

/*
 void manage_tasks() {
 char cmd[80];// ?

 meniu();

 while (1) {
 printf(">");
 printf("Comanda: ");
 gets(cmd); //? crash if more than 80 chars
 if (strstr(cmd, "1") == cmd) {
 //add_task(cmd);
 printf("add..\n");
 } else if (strstr(cmd, "2") == cmd) {
 printf("..");
 } else if (strstr(cmd, "exit") == cmd) {
 break;
 } else {
 printf("Unknown command\n");
 }
 }
 }
 */
void load_meniu(Repo* repo) {
	int cmd;

	do {
		cerinte();

		printf("Comanda: \n");
		printf(">");
		scanf("%d", &cmd);

		switch (cmd) {
		case 1:
			adaugare_masina(repo);
			break;
		case 2:
			print_masini(repo);
			break;
			//
		case 3:
			printf("Quitting program...\n");
			break;
		default:
			printf("Invalid command!\n");
			break;
		}
		printf("\n");
	} while (cmd != 3);

}

void cerinte() { //
	printf("1.Adaugare masina noua.\n");
	printf("2.Afiseaza lista cu masinile inregistrate.\n");
	printf("3.Exit.\n");

}

void adaugare_masina(Repo* repo) {

	char categorie[20], model[20], licenta[20];

	printf("Dati licenta: ");
	scanf("%s", licenta);

	printf("Dati model: ");
	scanf("%s", model);

	printf("Dati categorie: ");
	scanf("%s", categorie);

	create_car(repo, licenta, model, categorie, 1); //1 - masina nou adaugata este libera
	//informez

}

void print_masini(Repo* repo) {
	Car *cars = get_cars(repo);

	int i;
	for (i = 0; i < lungime_sir(cars); i++) {
		printf("Masina: licenta: %s, model: %s, categoria: %s",
				(cars[i])->licenta, (cars[i])->model, (cars[i])->categorie);

	}
}

