#include "SPARSEMAT.h"

struct _Matrix{
	int cap;
	int** elem;
};

void init(Matrix& m,int n){
	m=new _Matrix;
	m->cap=n;
	m->elem=new int*[n];
	for (int i=0;i<n;i++)
		m->elem[i]=new int[n];

	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			m->elem[i][j]=0;		
}

void destroy(Matrix& m){
	for (int i=0;i<m->cap;i++)
		delete [] m->elem[i];
	delete [] m->elem;
	delete m;
}

void setelem(Matrix m,int row,int col,int val){
	m->elem[row-1][col-1]=val;
}

int getelem(Matrix m,int row,int col){
	return m->elem[row][col];
}

int valid(int row,int col,int val){
	if (row==0&&col==0&&val==0) return 0;
	return 1;
}

void multiply(Matrix m1,Matrix m2,Matrix m3){
	for (int i=0;i<m3->cap;i++)
		for (int j=0;j<m3->cap;j++)
			m3->elem[i][j]=0;

	for (int i=0;i<m3->cap;i++)
		for(int j=0;j<m3->cap;j++)
			for(int k=0;k<m3->cap;k++)
			    m3->elem[i][j]+=m1->elem[i][k]*m2->elem[k][j];
}

void d(Matrix a,int j,Matrix &r){
	int i,k; 
	init(r,a->cap-1);
	for (i=1; i<a->cap;i++)
		for (k=0;k<a->cap;k++)
			if(k<j) r->elem[i-1][k]=a->elem[i][k];
			else if(k>j) r->elem[i-1][k-1]=a->elem[i][k];
}

int det(Matrix a){
	int j,sign,dt;
    Matrix r;
    if (a->cap==1)
      dt=a->elem[0][0];
    else {
		dt=0;
		for (j=0;j<a->cap;j++){
			d(a,j,r);
			if ((j%2)==0) sign=1;
			else sign=-1;
			dt=dt+(a->elem[0][j]*sign*det(r));
			}
	}
	return dt;
}
void copymat(Matrix m1,Matrix m2){
	for (int i=0;i<m1->cap;i++)
		for (int j=0;j<m1->cap;j++)
			m2->elem[i][j]=m1->elem[i][j];
}

void printmat(Matrix m){
	for(int i=0;i<m->cap;i++){
		for (int j=0;j<m->cap;j++)
			cout<<m->elem[i][j]<<" ";
		cout<<endl;
	}
}






