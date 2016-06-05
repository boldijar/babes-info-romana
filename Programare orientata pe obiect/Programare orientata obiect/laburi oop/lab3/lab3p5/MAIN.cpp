#include "sorted.h"
#include <iostream>
using namespace std;

void read(vector*& vect,int& n){
	int j;
	cout<<"the number of vectors is:";
	cin>>n;
	
	vect = new vector[n];

	for(int i=0;i<n;i++){
		cout<<"the number of elements is: ";
		int nr;
		cin>>nr;
		init(vect[i],nr);
		for(j=0;j<nr;j++){
            cout<<"v"<<i<<".["<<j<<"]=";		
			cin>>vect[i].elem[j];	
			vect[i].size++;
		}
	    sort(vect[i]);
	}
}

void print(vector v){
	for (int j=0;j<v.size;j++)
		cout<<v.elem[j]<<" ";
}


int main(){
	int siz,n,i;
	vector rez,result;
    vector* vect;

    read(vect,n);

	for(i=0;i<n;i++)
		elimin(vect[i]);
	
	siz=0;
	for(i=0;i<n;i++)
		siz+=vect[i].size;

    	init(rez,siz);
	init(result,siz);
	
	for(i=0;i<n;i++){
		if(i%2)
			merge(rez,vect[i],result);
		else
			merge(result,vect[i],rez);
	}
	if(i%2)
		print(rez);
	else
		print(result);
	destroy(result);
	destroy(rez);

    for (i=0;i<n;i++)
		destroy(vect[i]);
    system("pause"); 

	return 0;
}




		


