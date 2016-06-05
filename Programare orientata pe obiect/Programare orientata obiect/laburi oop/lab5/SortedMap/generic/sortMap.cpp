#include "sortMap.h"
#include "TElem.h"
#include <iostream>
using namespace std;
struct _map{
		TElem* elem;
		copyFun cpy;
		cmpFun cmp;
		delFun del;
		int cap,n;
		};
struct _Iterator{
		map m;
		int crt;
		};
void init(map &m,copyFun cpy,cmpFun cmp,delFun del,int c){
	m=new _map;
	m->elem=new TElem[c];
	m->cap=c;
	m->n=0;
	m->cpy=cpy;
	m->cmp=cmp;
	m->del=del;
}
bool isEmpty(map m){
	if (m->n==0) return true;
	return false;
}
int getSize(map m){
	return m->n;
}
bool belongs(map m,TElem e){
	for(int i=0;i<m->n;i++)
			if (m->cmp(m->elem[i],e)==0) return true;
	return false;
}
void addElem(map &m,TElem e){
	int i=0;
	if (!belongs(m,e)){
		if (m->n==0){  //if empty add on first position 
			m->cpy(m->elem[m->n],e);
			m->n++;
		}
		else {
			while ( (i< m->n) && (m->cmp(m->elem[i],e)==-1)) i++; //ignore the elemts that are smaller than e
			m->n++;
			for (int j=m->n-1;j>=i+1;j--)
					m->cpy(m->elem[j],m->elem[j-1]);
			
			m->cpy(m->elem[i],e);
		}
	}
	else cout<<"The key must be unique!!!";
}
Iterator create(map m){
	Iterator it=new _Iterator;
	it->m=m;
	it->crt=0;
	return it;
}
void  next(Iterator &it){
	it->crt++;
}
int valid(Iterator it){
	return (it->crt<it->m->n);
}

TElem elem(Iterator it){
	return it->m->elem[it->crt];
}
void destroy(map &m){
	for(int i=0;i<m->n;i++)
		m->del(m->elem[i]);
	delete [] m->elem;
	delete m;
}
void destroyIt(Iterator &it){
	delete it;
}