#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <fstream.h>
ifstream is;

const max = 333;

void initc (int& n,int& m,int d[30][30],int a[30][30])
	{
	is >> n;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			{
				d[i][j] = max;
				d[i][i] = 0;
			}
	for (i = 1;i <= n;i++)
		for (j = 1;j <= n;j++)
			a[i][j] = 0;
	is >> m;
	int x,y,v;
	for (i = 1;i <= m;i++)
		{
			is >> x;
			is >> y;
			is >> v;
			a[x][y] = 1;
			d[x][y] = 1;
		}
	}


void maxim (int n,int d[30][30],int e[30])
	{

		for (int i = 1;i <= n;i++)
			{
				e[i] =   d[i][1];
				for (int j = 2;j <= n;j++)
					if (e[i] < d[i][j]) e[i] = d[i][j];
			}
	}

int minim (int n,int e[30])
	{
		int min = e[1];
		for (int i = 2;i <= n;i++)
			if (min > e[i]) min = e[i];
		return min;
	}

int gaseste (int n,int d[30][30])
	{
		int g = 0,r = 1;
		while ((r <= n) && (g == 0))
		 {
		    int t = 1;
		    while ((t <= n) && (g == 0))
		     {
		       if (d[r][t] == max) g = 1;
		       t = t + 1;
		     }
		    r = r + 1;
		 }
		 return g;
	 }
void drum (int n,int a[30][30],int d[30][30])
	{
		int f[30][30],b[30][30];
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				f[i][j] = a[i][j];
		int p = 1;
		while ((p <= n) && (gaseste(n,d) == 1))
		{
		for (int q = 1;q <= n;q++)
			for (int w = 1;w <= n;w++)
				b[q][w] =  0;
		for (i = 1;i <= n;i++)
			for (j = 1;j <= n;j++)
				for (int k = 1;k <= n;k++)
					b[i][j] =  b[i][j] + f[i][k] * a[k][j];
		for (i = 1;i <= n;i++)
			for (j = 1;j <= n;j++)
			f[i][j] = b[i][j];
		for (i = 1;i <= n;i++)
		 for (j = 1;j <= n;j++)
		  if ((i != j) && (d[i][j] == max) && (b[i][j] !=0)) d[i][j] = p;
		  cout << endl;
		  p++;
		}
	}

void main()
	{
		clrscr();
		is.open ("input.txt");
		int n,m,d[30][30],e[30],a[30][30];
		initc (n,m,d,a);
		drum (n,a,d);
		for (int i = 1;i <= n;i++)
			{
			cout << endl;
			for (int j = 1;j <= n;j++)
				cout << d[i][j] << "   ";
			}
		maxim (n,d,e);
		cout << endl;
		cout << "Raza grafului este: " << minim (n,e);
	 }

