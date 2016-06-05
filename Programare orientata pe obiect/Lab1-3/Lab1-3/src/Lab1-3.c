#include <malloc.h>
#include "Repository/repository.h"
#include "Utils/vector/vector.h"
#include "Tests/test.h"
#include "Controller/controller.h"
#include "UI/ui.h"

void RunTests()
{
	Test tests;
	test_init(&tests);
	test_Run(&tests);
	test_destroy(&tests);
}

void RunUI()
{
	Repository* repo = malloc(sizeof(Repository));
	Controller* ctrl = malloc(sizeof(Controller));
	controller_init(ctrl, repo);

	UI* ui = malloc(sizeof(UI));
	ui_init(ui, ctrl);

	ui_run(ui);

	ui_destroy(ui);
	controller_destroy(ctrl);

	free(ui);
	free(ctrl);
	free(repo);
}

int main()
{
	setbuf(stdout, NULL);
	setbuf(stderr, NULL);

	RunTests();

	RunUI();

	return 0;
}
