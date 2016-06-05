/* Autor: Daraban Cristian - Adrian
 * Grupa 212
 */

// 1. Generate all the prime numbers smaller than a given natural number n.
#include <iostream>

using namespace std;

int isPrime(int n)
{
    if(n<2) return 0;
    if(n%2 == 0 && n != 2) return 0;
    for(int d=3; d*d<=n; d+=2)
        if(n%d==0)
            return 0;
    return 1;
}

void GeneratePrimes(int n)
{
    if(n==1) cout<<"2";
    else if(n>1)
    {
        cout<<"2";
        for(int i=3; i<=n; i+=2)
            if(isPrime(i))
                cout<<" "<<i;
    }
}

int main()
{
    int n;
    cout<<"Pana la ce numar sa se genereze numerele prime ?"<<endl<<"n: ";
    cin>>n;
    GeneratePrimes(n);
    return 0;
}
