/*
 * ui.h
 *
 *  Created on: Mar 10, 2015
 *      Author: Nexflame
 */

#ifndef UI_UI_H_
#define UI_UI_H_

#include "../Controller/controller.h"

typedef enum enum_Commands
{
	CMD_SHOW_OBJECTS			= 1,
	CMD_ADD_OBJECT,
	CMD_DELETE_OBJECT,
	CMD_UPDATE_OBJECT,
	CMD_FILTER_OBJECTS_PRICE,
	CMD_FILTER_OBJECTS_DATE,
	CMD_FILTER_OBJECTS_MANUFACTURER,
	CMD_SORT_OBJECTS_PRICE_ASC,
	CMD_SORT_OBJECTS_PRICE_DSC,
	CMD_SORT_OBJECTS_DATE_ASC,
	CMD_SORT_OBJECTS_DATE_DSC,
	MAX_COMMANDS,

	EXIT_CMD 					= 0,
	ERROR_CMD					= -1
}Commands;

typedef struct struct_UI
{
	Controller* ctrl;
}UI;

// Private:
void ui__printMenu();
int ui__getCMD();
void ui__execCMD();

// Public:
void ui_init(UI* this, Controller* ctrl);
void ui_destroy(UI* this);

// Commands
void ui_execCMDShowAllObjects(UI* this);
void ui_execCMDAddObject(UI* this);
void ui_execCMDDeleteObject(UI* this);
void ui_execCMDUpdateObject(UI* this);
void ui_execCMDFilterObjects(UI* this, FilterType filter);
void ui_execCMDSortObjects(UI* this, SortType sort, int asc);

void ui_run(UI* this);

#endif /* UI_UI_H_ */
