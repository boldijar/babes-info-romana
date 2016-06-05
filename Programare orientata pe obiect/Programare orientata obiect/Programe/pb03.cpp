/*
 * Autor: Daraban Cristian - Adrian
 * Grupa 212
 */

// 3. Determina toate reprezentarile posibile a unui numar natural ca suma
// de numere naturale consecutive.
#include <iostream>

using namespace std;

void NumberRepresentationAsSum(int n)
{
    int sum, k, ok;
    cout<<"Reprezentarile posibile ale lui "<<n<<" ca suma de numere consecutive:"<<endl;
    for(int i=1; i<=n/2+1; i++)
    {
        sum=i;
        k=i;
        ok=1;
        while(ok!=0 && ok!=-1)
        {
            k++;
            sum+=k; // sum +=++sum;
            if(sum==n)
                ok=0; // we found a solution
            else if(sum>n)
                ok=-1; // no need to search, no valid solution
        }
        if(ok==0)
        {
            for(int j=i; j<=k; j++)
                cout<<j<<" ";
            cout<<endl;
        }
    }
}


int main()
{
    int n;
    cout<<"Pentru ce numar doriti reprezantariile ca sume de numere consecutive ?"<<endl<<"n: ";
    cin>>n;
    NumberRepresentationAsSum(n);
    return 0;
}
