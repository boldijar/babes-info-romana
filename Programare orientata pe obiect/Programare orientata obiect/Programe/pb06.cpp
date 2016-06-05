/*
 * Autor: Daraban Cristian - Adrian
 * Grupa 212
 */
// 6. Tiparste triunghiul lui Pascal, cu toate combinarile C(m,k) de m obiecte
//   luate cite k, k = 0, 1, ..., m, in linia m, pentru m = 1, 2, ..., n.

#include <iostream>

using namespace std;

void PascalsTriangle(int n)
{
    long long a[n+2][n+2];
    a[1][1]=1;
    for(int i=2; i<=n+1; i++)
    {
        a[i][1]=1;
        for(int j=2; j<=i-1; j++)
            a[i][j]=a[i-1][j]+a[i-1][j-1];
        a[i][i]=1;
    }
    for(int i=1; i<=n+1; i++)
    {
        for(int j=1; j<=i; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int n;
    cout<<"Dimensiunea (2^n) triunghiului lui Pascal: ";
    cin>>n;
    PascalsTriangle(n);
    return 0;
}
