#ifndef SPARSEMAT_H
#define SPARSEMAT_H
#include <iostream>
using namespace std;

struct _Matrix;
typedef _Matrix* Matrix;

void init(Matrix&,int);
void destroy(Matrix&);
void setelem(Matrix,int,int,int);
int getelem(Matrix,int,int);
int valid(int,int,int);
void multiply(Matrix,Matrix,Matrix);
void d(Matrix,int,Matrix&);
int det(Matrix);
void copymat(Matrix,Matrix);
void printmat(Matrix);

#endif


