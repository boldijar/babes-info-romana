#include "sorted.h"

void init(vector& v,int c){
	v.cap=c;
	v.elem=new int[c];
	v.size=0;
}

void sort(vector& v){
	for(int i=0;i<v.size-1;i++)
		for(int j=i+1;j<v.size;j++)
			if(v.elem[i]>v.elem[j]){
				int aux=v.elem[i];
				v.elem[i]=v.elem[j];
				v.elem[j]=aux;
			}
}

int insert(vector& v,int x){
	for(int i=0;i<v.size-1;i++)
		if(v.elem[i]<x&&v.elem[i+1]>=x){
			v.size++;
			for(int j=v.size-1;j>i+1;j--)
				v.elem[j]=v.elem[j-1];
			v.elem[i+1]=x;
			break;
		}
    if(v.elem[0]>x){
		v.size++;
		for(int i=v.size-1;i=0;i--)
			v.elem[i]=v.elem[i-1];
		v.elem[0]=x;
	}
	if(v.elem[v.size-1]<x)
		v.elem[++v.size]=x;
return 0;
}

void merge(vector v1,vector v2,vector& rez){
	int i=0;
	int j=0;
	rez.size=0;
	while (i<v1.size&&j<v2.size){
		if (v1.elem[i]<=v2.elem[j]){
			rez.elem[rez.size++]=v1.elem[i++];
		}
		else{
			rez.elem[rez.size++]=v2.elem[j++];
		}
	}
	if (i<v1.size){
		for(int k=i;k<v1.size;k++)
			rez.elem[rez.size++]=v1.elem[k];
	}
	if (j<v2.size){
		for(int k=j;k<v2.size;k++)
			rez.elem[rez.size++]=v2.elem[k];
	}
}

void remove(vector& v,int s,int e){
	v.size-=e-s+1;
	for (int j=s;j<v.size;j++)
		v.elem[j]=v.elem[j+e-s+1];
}

int elimin(vector& v){
	int s=-1;
	int e=-1;
	int len=0;
	int ok=0;

	while(ok==0){
        ok=1; 
        for (int j=0;j<v.size-1;j++)
	    	if(v.elem[j]==v.elem[j+1]-1){
		    	ok=0;
	         	s=j;
	        	len=1;
	        	while((v.elem[j]==v.elem[j+1]-1)&&(j<v.size)){
	        	    len++;
		            j++;
	     	    }
	            e=s+len-1;
        		remove(v,s,e);
	    	}
	 }

return 0;
}

void destroy(vector& v){
	delete [] v.elem;
	v.size=-1;
}

   
