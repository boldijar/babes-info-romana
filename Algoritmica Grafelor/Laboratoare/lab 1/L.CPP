/*Cunoscandu-se reprezentarea unui graf prin matricea de incidenta,se cere sa se
gaseasca reprezentarea grafului prin matricea de adiacenta*/
#include <iostream.h>
#include <stdio.h>

void Citesc (int& n,int& m,int b[30][30])
	{
		cout <<"Introduceti numarul varfurilor:";
		cin >> n;
		cout << "Introduceti numarul muchiilor:";
		cin >> m;
		for (int i = 1;i <= n;i++)
			 for (int j = 1;j <= m;j++)
				{
					cout << "b[" << i << "," << j << "]=";
					cin >> b[i][j];
				}
	}

void Transforma (int& n,int& m,int b[30][30],int a[30][30])
	{
		int k,h;
		for (int i = 1;i <= n; i++)
			for (int j = 1;j <= n;j++)
				a[i][j] = 0;
		for (j = 1;j <= m;j++)
		       {
				for (i = 1;i <= n;i++)
					{
						if (b[i][j] == 1) k = i;
						if (b[i][j] == -1) h = i;
					}
				a[k][h] = 1;
			}
	}

void Scrie (int n,int a[30][30])
	{
		for (int i = 1;i <= n;i++)
			{
				cout << endl;
				for (int j = 1;j <= n;j++)
					cout << a[i][j] << "   ";
			}
	}

void main ()
	{
		int n,m,a[30][30],b[30][30];
		Citesc (n,m,b);
		Transforma (n,m,b,a);
		Scrie (n,a);
	}