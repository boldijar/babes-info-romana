#include <iostream>
#include <conio.h>
using namespace std;
void printm(int a[30][30],int n)
{int i,k,j;
	
	for(i=0;i<=n;i++){
	   for(k=0;k<=n-i;k++) cout<<" ";
		 for(j=0;j<=i;j++)	cout<<a[i][j]<<" ";
    cout<<endl;
	}
}

int main()
{ 
	
int i,j,n,a[30][30];
cout<<"Give n:";

cin>>n;
	for (i=0;i<=n;i++)
	{
		a[i][i]=1;
	    a[i][0]=1;
	}
	
	for(i=2;i<=n;i++)
		for(j=1;j<=i-1;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
	printm(a,n);
	getch();
	return 0;
}