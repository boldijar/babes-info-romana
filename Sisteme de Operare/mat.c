#include<stdlib.h>
#include<stdio.h>

int main(){
	int m=2,n=2,p=2,q=2,r=2,s=0;
	int a[5][5][5][5][5];
	int i,j,z,t,y;

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			for(z=0;z<p;z++)
				for(t=0;t<q;t++)
					for(y=0;y<r;y++)
						a[i][j][z][t][y] = 1;
	
	
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			for(z=0;z<p;z++)
				for(t=0;t<q;t++)
					for(y=0;y<r;y++)
						s=s+a[i][j][z][t][y];
				

	printf("Suma: %d\n",s);
	return 0;
}
