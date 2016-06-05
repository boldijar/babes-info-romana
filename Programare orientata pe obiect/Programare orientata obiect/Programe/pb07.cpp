/*
 * Autor: Daraban Cristian - Adrian
 * Grupa 212
 */
// 7. Calculeaza o valoare aproximativa a radacinii patrate a unui numar
//   real pozitiv, cu o precizie data.

#include <iostream>
#include <cmath>
#include <iomanip>
#include <conio.h>
using namespace std;

void PrecisionMathSqrt(double n, int k)
{
    double result;
    result = sqrt(n);
    cout<<"Radacina patrata a lui "<<n<<" este : "<<setprecision(k+1)<<result;
}

int main()
{
    int n,k;
    cout<<"Numarul pentru care sa se calculeze radacina patrata: ";
    cin>>n;
    cout<<"Precizia acesteia (<53): ";
    cin>>k;
    PrecisionMathSqrt(n,k);
    getch();
    return 0;
}
