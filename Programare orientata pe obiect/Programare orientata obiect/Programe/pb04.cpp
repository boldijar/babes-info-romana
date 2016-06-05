/*
 * Autor: Daraban Cristian - Adrian
 * Grupa 212
 */

// 4. Determina primele n cifre din scrierea fractiei subunitare
//  k/m = 0.c1c2c3..., pentru k si m numere naturale date.
#include <iostream>

using namespace std;

void GetFractionsFirstNDigits(int k, int m, int n)
{
    int tmp[64],i=0;
    double result;
    result=(double)k/(double)m;
    while(i<64)
    {
        result *=10;
        tmp[i++]=int(result);
        result = result - (int)result;
        if (result==0)
            i=64;
    }
    cout<<"Primele "<<n<<" cifre "<<k<<"\\"<<m<<" sunt : "<<endl;
    for(i=0; i<n; i++)
        if(tmp[i]<=9 && tmp[i]>=0)
            cout<<tmp[i]<<" ";
        else cout<<0<<" ";
}

int main()
{
    int n,m,k;
    cout<<"Numaratorul fractiei: ";
    cin>>k;
    cout<<"Numitorul fractiei: ";
    cin>>m;
    cout<<"Cate cifre sa fie determinate ? (n<=50)";
    cin>>n;
    GetFractionsFirstNDigits(k,m,n);
    return 0;
}
