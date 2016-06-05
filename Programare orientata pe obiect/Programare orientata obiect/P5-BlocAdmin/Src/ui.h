/*
 * ui.h
 *
 *  Created on: 24.03.2012
 *      Author: Florin Mihalache
 */

#ifndef UI_H_
#define UI_H_

/* Writes all the apartments with an overall expense greater than a given amount */
void writeGreaterThan(aptList* apts, float amount);

/* Writes apartments from 1 to a given apartment number with an overall expense less than a given amount */
void writeLessThan(aptList* apts, float amount, int aptNumber);

/* Writes all the expenses having the specified type */
void writeAllType(aptList* apts, string type);

/* Writes the sold (total amount of expenses) for given apartment */
void writeSold(aptList* apts, int aptNumber);

/* Writes the total amount for the expenses having the specified type */
void writeSumType(aptList* apts, string type);

/* Writes the maximum expense per type for given apartment */
void writeMaxType(aptList* apts, int aptNumber);

/* Prints menu options */
void printMenu();

/* The menu */
void menu(aptList* apts);

/* Shows all the expenses */
void showAll(aptList* apts);

/* UI for adding expense */
void addExpense(aptList* apts);

/* UI for modifying expenses */
void modifyExpenses(aptList* apts);

/* UI for removing expenses at given apartment */
void removeExpAptUi(aptList* apts);

/* UI for removing expenses for a range of apartments */
void removeExpRangeUi(aptList* apts);

/* UI for removing all expenses of a given type */
void removeAllByTypeUi(aptList* apts);

/* UI for writing expenses having different properties */
void writePropertiesUi(aptList* apts);

/* UI for obtaining different characteristics of expenses */
void obtainChUi(aptList* apts);

/* UI for filtering the list of expenses */
void filterListUi(aptList* apts);

/* UI for undo */
void undoUi(aptList* apts);

#endif /* UI_H_ */
