/*
 * Autor: Daraban Cristian - Adrian
 * Grupa 212
 */
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

void GenerateNPrimeNumbers(int n)
{
    //n>0
    cout<<"Primele "<<n<<" numere prime sunt:"<<endl;
    cout<<"2"; // the first prime number
    int startAt=3;
    for(int i=1; i<n; i++)
    {
        int ok=1;
        while(ok)
        {
            if(isPrime(startAt)==1)
            {
                cout<<" "<<startAt;
                startAt+=2;
                ok=0;
            }
            else //keep on searching
                startAt+=2;
        }
    }
}



int main()
{
    int n;
    cout<<"Cate numere prime sa se genereze ?"<<endl<<"n: ";
    cin>>n;
    GenerateNPrimeNumbers(n);
    return 0;
}
