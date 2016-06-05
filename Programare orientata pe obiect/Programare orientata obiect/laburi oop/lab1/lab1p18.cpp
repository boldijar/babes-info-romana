/*18. Determina primele n perechi de numere prime gemene, unde n este un
    numar natural nenul dat. Doua numere prime p si q sunt gemene
    daca q-p = 2.

*/
#include <iostream>

using namespace std;

int prime(int n){
    int i;
    for(i=2;i<=n/2;i++)
        if(n%i==0)
            return 0;
    return 1;
}

int main(){
    int n;
    cin>>n;
    int a,b;
    a=3;
    b=2;
    while(n>0){
        if (a-b > 2)
            b=a;
        else
            if(a-b < 2)
                while(!prime(++a));
            else{
                cout<<a<<" "<<b<<endl;
                b=a;
                n--;
            }
    }
    return 0;
}
