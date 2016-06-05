/*
        John wants to manage its bank account. In order to complete this task, John needs an application to store,
for a certain month, all the banking transactions which were performed on his account. Each transaction will
be stored in the application through the following elements: day (of the month in which the transaction was
made), amount of money transferred into/from the account, the type of the transaction (into the account – in
or from the account - out), and description of the transaction.  Please help John to create an application in
order to repeatedly execute the following functionalities (each functionality is exemplified):
1. Add a new transaction into the list.
• add 100, out , description– adds to the current day an out transaction of 100 RON with the
given description

• insert 25, 100, in, description – inserts in day 25 an in transaction of 100 RON with the
given description
2. Modify  transactions  from the list.

• remove 15 – removes all the transactions from day 15
• remove from 5 to 10 – removes all the transactions from day 5 until day 10
• remove in – removes all the in transactions from the current month
• replace 12, in, description  with 200 – replaces the amount  for the in transaction having
the specified description  from day 12 with 200 RON

3. Write the transactions having different properties.
• greater than 100 -  writes all transactions greater than 100
• less than 100 before 15 - writes all transactions less than 100 which were made before
day 15
• all in – writes all the in transactions.
• Sold 10 – computes the account’s sold on day 10

4. Obtain different characteristics of transactions.
• sum in– writes the total amount from in  transactions
• max out day – writes the day with the maximum amount in an out transaction
• asc sort day – sorts the total daily transactions in an ascending order
• desc sort type - sorts the total daily transactions per type (in, out) in a descending order

5. Filter.
• filter in – retains only the in transactions.
• filter out 100 – retains only the out transactions greater than 100 RON

6. Undo the last operation.
• undo – the last operation that has modified the list of transactions is cancelled.
*/

#include <iostream>
#include <string>

#include "node.h"
#include "arrmanip.h"
#include "userinterface.h"
#include "controller.h"
using namespace std;

int main()
{
    int cmd= -1;
    Controller ctrl;
    UserInterface UI;
    UI.SetController(ctrl);

    while(cmd != 0)
    {
        UI.DisplayMenu();
        UI.GetCommand(cmd);
        UI.AnalyzeCommand(cmd);
    }
    //cout<<"CMD:"<<cmd;
}
