#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <time.h>


#include "userinterface.h"
#include "controller.h"
#include "arrmanip.h"

using namespace std;

/// Data defining
#define MAX_USER_OUTPUT_INT 20
#define cmdArray { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 0 };

UserInterface::UserInterface()
{
    //ctor
}

UserInterface::~UserInterface()
{
    //dtor
}

void UserInterface::DisplayMenu()
{
    int cmd[] = cmdArray;
    // Menu Header
    cout<<setfill('.')<<left<<setw(54)<<"Descrierea"<<"Comanda"<<endl;
    cout<<setfill('=')<<setw(61)<<""<<endl;
    // Menu Context
    cout<<setfill('.')<<left<<setw(54)<<"Add transaction current day "<<"   "<<cmd[0]<<endl
        <<left<<setw(54)<<"Insert transaction "<<"   "<<cmd[1]<<endl
        <<left<<setw(54)<<"Remove transactions from a day "<<"   "<<cmd[2]<<endl
        <<left<<setw(54)<<"Remove transaction for a specified period "<<"   "<<cmd[3]<<endl
        <<left<<setw(54)<<"Remove in/out transactions "<<"   "<<cmd[4]<<endl
        <<left<<setw(54)<<"Replace transaction "<<"   "<<cmd[5]<<endl
        <<left<<setw(54)<<"Transaction greater than "<<"   "<<cmd[6]<<endl
        <<left<<setw(54)<<"Transactions less than until specified day "<<"   "<<cmd[7]<<endl
        <<left<<setw(54)<<"Write in/out transactions"<<"   "<<cmd[8]<<endl
        <<left<<setw(54)<<"Accounts sold "<<"   "<<cmd[9]<<endl
        <<left<<setw(54)<<"Total amount of in transactions "<<"   "<<cmd[10]<<endl
        <<left<<setw(54)<<"Max in/out amount day "<<"   "<<cmd[11]<<endl
        <<left<<setw(54)<<"Sort in an ascending order "<<"   "<<cmd[12]<<endl
        <<left<<setw(54)<<"Sort in a descending order "<<"   "<<cmd[13]<<endl
        <<left<<setw(54)<<"Filter transactions "<<"   "<<cmd[14]<<endl
        <<left<<setw(54)<<"Filter in/out transactions greater than"<<"   "<<cmd[15]<<endl
        <<left<<setw(54)<<"Write transactions "<<"   "<<cmd[16]<<endl
        <<left<<setw(54)<<"Undo "<<"   "<<cmd[17]<<endl
        <<left<<setw(54)<<"Exit "<<"   "<<cmd[18]<<endl;


}

void UserInterface::GetCommand(int& data)
{
    cin >> data;
}


void UserInterface::AnalyzeCommand(int cmd)
{
    int day;
    float amount;
    bool in;
    string description;

    switch(cmd)
    {


// Adds a transaction to current day

    case 1:
    {
        time_t currentTime;
        time (&currentTime);
        Tranzactie nou;
        struct tm * ptm= localtime(&currentTime);
        nou.day = ptm->tm_mday;
        cout << "Amount: ";
        cin >> nou.amount;
        cout << "0-Out 1-In";
        cout << "\nType: ";
        cin >> nou.in;
        cout << "Description: ";
        cin >> nou.description;
        GetController().AddToList(nou);
    }

    break;

    // Inserts transaction
    case 2:
    {
        Tranzactie nou;
        cout << "\nDay: ";
        cin >> nou.day;
        cout << "Amount: ";
        cin >> nou.amount;
        cout << "0-Out 1-In";
        cout << "\nType: ";
        cin >> nou.in;
        cout << "Description: ";
        cin >> nou.description;
        GetController().AddToList(nou);
    }
    break;

    // Removes transaction by day
    case 3:
    {
        cout << "\nDay: ";
        cin >> day;
        GetController().RemoveByDay(day);
    }
    break;

    // Removes transactions from day1 to day2
    case 4:
    {
        int day1,day2;
        cout << "\nFrom day: ";
        cin >> day1;
        cout << "To day: ";
        cin >> day2;
        for (int i=day1; i<=day2; i++)
            GetController().RemoveByDay(i);
    }
    break;

    // Removes in/out transactions
    case 5:
    {
        bool in;
        cout << "\n0-Out 1-In";
        cout << "\nType: ";
        cin >> in;
        GetController().RemoveIfIn(in);
    }
    break;

    // Replaces transaction
    case 6:
    {
        Tranzactie vechi, nou;
        cout << "\nDay: ";
        cin >> day;
        cout << "0-Out 1-In";
        cout << "\nType: ";
        cin >> in;
        cout << "Description: ";
        cin >> description;
        cout << "Amount: ";
        cin >> amount;
        vechi.day = day;
        vechi.in = in;
        vechi.description = description;
        vechi.amount = 0;
        nou = vechi;
        nou.amount = amount;
        List<Tranzactie> lVechi, lNou;
        lVechi.addLast(vechi);
        lNou.addLast(nou);
        GetController().ReplaceAll(lVechi, lNou);
    }
    break;

    // Transactions greater than
    case 7:
    {
        cout << "\nAmount: ";
        cin >> amount;
        List<Tranzactie> lista = GetController().getGreaterThan(amount);
        List<Tranzactie>::iterator it = lista.begin();
        for (int i=0; i<lista.countElements(); i++){
            cout << "Day > " << it.getElement().day << ";  Amount > " << it.getElement().amount << ";  Type > " << it.getElement().in << ";  Description > " << it.getElement().description << endl;
            it.nextElement();

        }
    }
    break;

    // Transacations less than "amount" until "day"

    case 8:
    {
        cout << "\nAmount: ";
        cin >> amount;
        cout << "Day: ";
        cin >> day;
        List<Tranzactie> lista = GetController().getLessThan(amount);
        List<Tranzactie>::iterator it = lista.begin();
        for (int i=0; i<lista.countElements(); i++){
            if (it.getElement().day < day)
            cout << "Day > " << it.getElement().day << ";  Amount > " << it.getElement().amount << ";  Type > " << it.getElement().in << ";  Description > " << it.getElement().description << endl;
            it.nextElement();
}
    }
    break;


    // Writes all in/out transactions

    case 9:
    {
        bool type;
        cout << "\n0-Out 1-In";
        cout <<"\nType: ";
        cin >> type;
        List<Tranzactie> lista = GetController().getType(type);
        List<Tranzactie>::iterator it = lista.begin();
        for (int i=0; i<lista.countElements(); i++){

            cout << "Day > " << it.getElement().day << ";  Amount > " << it.getElement().amount << ";  Type > " << it.getElement().in << ";  Description > " << it.getElement().description << endl;
            it.nextElement();
}
    }
    break;

// Computes accounts sold on user input day

    case 10:
    {
        float sum;
        int day;
        cout << "\nDay: ";
        cin >> day;
        List<Tranzactie> lista = GetController().getDayElements(day);
        List<Tranzactie>::iterator it = lista.begin();
        for (int i=0; i<lista.countElements(); i++){
            sum =  sum + it.getElement().amount;
            it.nextElement(); }
        cout << "Sold= " << sum << endl;

    }
    break;

// Writes the total amount from in/out  transactions

    case 11:
    {
        int sum;
        bool type;
        cout << "\n0-Out 1-In";
        cout << "\nType: ";
        cin >> type;
        List<Tranzactie> lista = GetController().getElementsInOut(type);
        List<Tranzactie>::iterator it = lista.begin();
        for (int i=0; i<lista.countElements(); i++){
            sum =  sum + it.getElement().amount;
            it.nextElement(); }
        cout << "Total amount= " << sum << endl;
    }
    break;

    //Max in/out day

    case 12:
    {
        int max = 1;
        float amount,maxAmount = 0;
        bool type;
        cout << "\n0-Out 1-In";
        cout << "\nType: ";
        cin >> type;

        for (int day=1; day<=31; day++){
            List<Tranzactie> dayList = GetController().getDayElements(day);
            List<Tranzactie>::iterator it = dayList.begin();

            for (int i=0; i<dayList.countElements(); i++){
            if (it.getElement().in == type)
                amount = amount + it.getElement().amount;
            it.nextElement(); }
            if (amount > maxAmount){
                max = day;
                maxAmount = amount;
        }

            }
        cout << "Max amount day:" << max << endl;
    }

//Sort

    case 13:
    {

    }
    break;

//Sort

    case 14:
    {

    }
    break;

//Filter in/out transactions

    case 15:
    {
        bool in;
        cout << "\n0-Out 1-In";
        cout << "\nType: ";
        cin >> in;
        GetController().FilterInOut(in);

    }
    break;

//Filter in/out transactions greater than

    case 16:
    {
        bool in;
        float a;
        cout << "\nGreater than: ";
        cin >> a;
        cout << "0-Out 1-In";
        cout << "\nType: ";
        cin >> in;
        GetController().FilterGreater(in,a);

    }
    break;

//Writes transactions

    case 17:
    {
        List<Tranzactie> list = GetController().GetList();
        Iterator<Tranzactie> it = list.begin();
        for (int i=0; i<list.countElements(); i++){
            cout << "Day > " << it.getElement().day << ";  Amount > " << it.getElement().amount << ";  Type > " << it.getElement().in << ";  Description > " << it.getElement().description << endl;
            it.nextElement();
        }
    }
    break;
    case 0:
    {
        cout<<"The application is closing !";
    }
    break;

//Undo

    case 18:
    {
        GetController().Undo();
    }
    break;
    }
}

