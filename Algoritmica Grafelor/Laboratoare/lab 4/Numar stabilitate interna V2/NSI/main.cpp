#include <iostream>
#include <fstream>

using namespace std;

int a[30][30],x[30],n,maxm;
void citire()
{   ifstream f("adiacenta.in");
    int i,j;
    f>>n;
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
        f>>a[i][j];
}

int ok(int k)
{
    int i;
    for (i=1;i<k;i++)
    {
        //if(x[i]==x[k])
          //  return 0;
        if(a[x[i]][x[k]]==1 || a[x[k]][x[i]]==1)
            return 0;
    }
    if(k>1 && x[k]<=x[k-1])
        return 0;
     return 1;
}

void afisare(int k)
{
    int i;
    for (i=1;i<=k;i++)
        cout<<x[i]<<" ";
    cout<<endl;
    if(k>maxm)
        maxm=k;
}

void back(int k)
{
    int i;
    for (i=1;i<=n;i++)
    {
        x[k]=i;
        if(ok(k))
            {
                afisare(k);
                back(k+1);
            }
    }
}
int main()
{
    citire();
    back(1);
    cout<<"Numarul de stabilitate interna :"<<maxm;
    return 0;
}
