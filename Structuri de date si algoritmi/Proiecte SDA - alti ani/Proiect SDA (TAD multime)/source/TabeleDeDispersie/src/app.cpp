/*
 * app.cpp
 *
 *  Created on: Jun 7, 2012
 *      Author: Admin
 */

#include "utils/TADMultime.h"
#include "Controller/ContainerController.h"
#include "Repository/ContainerRepository.h"
#include "UI/ConsoleUI.h"


void runApp() {
	ContainerRepository* containerRepo = new ContainerRepository;
	ContainerController* containerCtrl = new ContainerController(containerRepo);
	ConsoleUI consoleUI(containerCtrl);
	consoleUI.showUI();
}

int main() {
	runApp();
	return 0;
}

