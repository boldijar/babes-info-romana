/*6.: SPARE MATRIX 

Write a program that reads many spare matrices. Reading a matrix ends with the tuple (0,0,0). For each matrix print its determinant and in the end print the product of all read matrices.

*/
#include <iostream>
using namespace std;
#include "ADTMatrix.h"
#include <conio.h>

int main(){
	int nr,ord;
	_Matrix a,P,P1;
	cout<<"Give the number of matrix:";
	cin>>nr;
	cout<<"Give the order:";
	cin>>ord;
	P.n=ord;
	P.x=new int*[21];
	for(int i=1;i<=20;i++)
		P.x[i]=new int[21]; //Alocam spatiu pt. P
	for(int i=1;i<=ord;i++)
		for(int j=1;j<=ord;j++)
			if (i==j) P.x[i][j]=1;
			else P.x[i][j]=0;//P=I
	for(int i=1;i<=nr;i++){
		a.n=ord;
		read(a);
		cout<<"Det="<<Mdet(a)<<endl;
		Mimul(P,a,P1);
		P=P1;
		
	}
	print(P);

	getch();
}