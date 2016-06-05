/*
 ============================================================================
 Name        : helloworld.c
 Author      : Ioan Lazar
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ui.h"

/*
 * Task: text, status (active, done)
 * Commands:
 * add Learn C => Task("Learn C", ACTIVE)
 * list => ...
 * exit
 */

int main(void) {
	manage_tasks();
	return EXIT_SUCCESS;
}
