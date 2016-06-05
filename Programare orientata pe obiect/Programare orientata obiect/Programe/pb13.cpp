#include<iostream>

/*13.
    Determina o data calendaristica (sub forma an, luna, zi) pornind de
    la doua numere intregi care reprezinta anul si numarul
    de ordine al zilei in anul respectiv.
    Lucruri generale:
        Un an este bisect daca ultimele 2 cifre sunt divizibile cu 4 cu exceptia celor care se termina in 00 pentru care trebuie sa fie divizibile cu 400

*/
void GetUserInputYD(int &year, int &dayInYear)
{
    cout<<"Anul: "; cin>>year;
    cout<<"Ziua din anul "<<year<<" :"; cin>>dayInYear;
}

int isLeapYear(int year)
{
    if(year%4==0 && year%100!=0 || year%400==0)
        return 1;
    return 0;
}

void PrintDateAlgorithm(int year, int dayInYear)
{
    int DAYS_PER_MONTH[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int DAYS_IN_YEAR=365;
    int temp=0, month, day;
    if(isLeapYear(year))
        DAYS_IN_YEAR=366,DAYS_PER_MONTH[1]++;

    for(int i=0;i<12; i++)
    {
        temp+=DAYS_PER_MONTH[i];
        if(dayInYear <= temp)
        {
            month=i+1;
            day = DAYS_PER_MONTH[i] - (temp-dayInYear);
            break;
        }
    }
    if(DAYS_IN_YEAR == 366)
        cout<<"A "<<dayInYear<<" din anul "<<year<<"(An bisect) produce urmatoarea data: "<<day<<"."<<month<<"."<<year;
    else
        cout<<"A "<<dayInYear<<" din anul "<<year<<" produce urmatoarea data: "<<day<<"."<<month<<"."<<year;
}


int main()
{
    int year, dayInYear;
    GetUserInputYD(year,dayInYear);
    PrintDateAlgorithm(year,dayInYear);
    return 0;
}
