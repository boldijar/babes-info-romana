#include "SPARSEMAT.h"
#include <iostream>
#include <conio.h>
using namespace std;

void readmat(Matrix m){
    int r,c,v;
	cout<<"the row is:";
	cin>>r;
	cout<<"the column is:";
	cin>>c;
	cout<<"the value is:";
	cin>>v;
	setelem(m,r,c,v);
	while (valid(r,c,v)){
		cout<<"the row is:";
	    cin>>r;
    	cout<<"the column is:";
    	cin>>c;
    	cout<<"the value is:";
    	cin>>v;
		if(!r && !c && !v) break;
    	setelem(m,r,c,v);
	}
}



int main(){
	int n,nr,determinant;

	cout<<"the number of matrices is (more than 1):";
	cin>>nr;
	cout<<"the dimension of the matrices is:";
	cin>>n;

	Matrix finalmat,rez,m; 

	init(finalmat,n);
	init(rez,n);
	init(m,n);
	readmat(m);
	copymat(m,rez);
	determinant=det(m);
	cout<<"the determinant is:"<<determinant<<endl;
	destroy(m);

	for (int i=1;i<nr;i++){
		init(m,n);
		readmat(m);
		multiply(rez,m,finalmat);
		copymat(finalmat,rez);
		determinant=det(m);
		cout<<"the determinant is:"<<determinant<<endl;
		destroy(m);
	}

	cout<<"the multiplication of matrices is:"<<endl;
	printmat(finalmat);

	destroy(rez);
	destroy(finalmat);
	system("pause");
	return 0;
}









