/*
 * Autor: Daraban Cristian - Adrian
 * Grupa 212
 */
/*
5. Tipareste un numar precizat de termeni din sirul
   1, 2,1, 3,2,1, 4,2,2, 5,4,3,2,1, 6,2,2,3,3,3, 7,6, ...
   obtinut din sirul numerelor naturale prin inlocuirea fiecarui
   numar natural n printr-un grup de numere. Numarul prim p este
   inlocuit prin numerele p,p-1,...3,2,1, iar numarul compus n
   este inlocuit prin n urmat de toti divizorii sai proprii,
   un divizor d repetandu-se de d ori.
*/
#include <iostream>
#include <conio.h>
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

void GenerateNItems(int n)
{
    int i=2,j=0, isp,k=0;
    // daca e prim ... sa se genereze toate numele de la prim la 1
    // daca nu e prim sa se scrie toti divizorii d de d ori

    // Note as fi putut folosi break sa fie mai eficienta
    cout<<1<<" ";
    n--;
    while(n!=0)
    {
        isp=isPrime(i);
        if(isp==1)
            for(j=i;j>0;j--)
                if(n!=0)
                    cout<<j<<" ",n--;
        if(isp==0)
        {
            cout<<i<<" ";
            n--;
            for(j=2; j<=i/2; j++)
                if(i%j==0)
                    {
                        k=j;
                        while(k!=0)
                            if(n!=0)
                                cout<<j<<" ",n--,k--;
                            else k=0;
                    }
        }
        i++;
    }
}



int main()
{
    int n;
    cout<<"Cati termeni sa se tipareasca pe ecran ?"<<endl<<"n: ";
    cin>>n;
    GenerateNItems(n);
    //getch();
    return 0;
}
