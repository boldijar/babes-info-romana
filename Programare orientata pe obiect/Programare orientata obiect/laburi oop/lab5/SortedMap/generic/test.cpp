#include "sortMap.h"
#include "TElem.h"
#include <iostream>
#include <string>
#include <cstdio> 
using namespace std;
#include <conio.h> 
//Word in romanian and word in english
struct word{
			char* ro; //key
			char* en; //val
};
void cpyWord(TElem &dest,TElem source){
	dest=new word;
	((word*)dest)->ro=new char[strlen( ((word*)source)->ro )];
	strcpy( ((word*)dest)->ro,((word*)source)->ro );
	((word*)dest)->en=new char[strlen( ((word*)source)->en)];
	strcpy( ((word*)dest)->en,((word*)source)->en );
}
int cmpWord(TElem e1,TElem e2){
	return (strcmp(((word*)e1)->ro,((word*)e2)->ro));
}
void delWord(TElem &e){
	word *w=(word*)e;
	delete w;
}
void readMapW(map &m){
	char wr[30],we[30];
	int nr;
	TElem w;
	cout<<"Give the number of pairs:"; 
	cin>>nr;
	init(m,cpyWord,cmpWord,delWord,20);
	for (int i=0;i<nr;i++){
		cout<<"Word in romanian:";
		cin.get();
		cin.get(wr,30);
		//cin>>wr;
		cout<<"word in english:";
		cin.get();
		cin.get(we,30);
		w=new word;
		((word*)w)->ro=new char[strlen(wr)+1];
		((word*)w)->en=new char[strlen(we)+1];
		strcpy( ((word*)w)->ro,wr);
		strcpy( ((word*)w)->en,we);
		addElem(m,w);
		delWord(w);
	}
}
void printMapW(map m){
	TElem w;
	Iterator it;
	it=create(m);
	cout<<"(word , translation in english)"<<endl;
	while (valid(it)) {
		w=elem(it);
		cout<<"("<<((word*)w)->ro<<" , "<<((word*)w)->en<<")"<<endl;
		next(it);
	}
	destroyIt(it);
}
void searchByKeyW(map m){
	TElem w;
	char wr[30];
	bool found=false;
	Iterator it;
	it=create(m);
	cout<<"Give the key:";
	cin.get();
	cin.get(wr,30);
	while ((valid(it))&&(!found)){
		w=elem(it);
		if (strcmp (((word*)w)->ro,wr)==0) {
			found=true;
			cout<<"The value coresponding to the key is: "<<((word*)w)->en<<endl;
		}
		next(it);
	}
	if (!found) cout<<"No value for the given key";
	destroyIt(it);
}
//Person (PIN,address)
struct person{
		int PIN;
		char* address;
};
void cpyPerson(TElem &dest,TElem source){
	dest=new person;
	((person*)dest)->address=new char[strlen( ((person*)source)->address )];
	strcpy( ((person*)dest)->address,((person*)source)->address );
	((person*)dest)->PIN=((person*)source)->PIN;
}
int cmpPerson(TElem p1,TElem p2){
	if ( ((person*)p1)->PIN < ((person*)p2)->PIN ) return -1;
	if ( ((person*)p1)->PIN > ((person*)p2)->PIN ) return 1;
	return 0;
}
void delPerson(TElem &e){
	person *p=(person*)e;
	delete p;
}
void readMapP(map &m){
	char adr[256];
	int pin;
	int nr;
	TElem p;
	cout<<"Give the number of pairs:"; 
	cin>>nr;
	init(m,cpyPerson,cmpPerson,delPerson,20);
	for (int i=0;i<nr;i++){
		cout<<"PIN:";
		cin>>pin;
		cout<<"Address:";
		cin.get();
		cin.get(adr,100);
		p=new person;
		((person*)p)->PIN=pin;
		((person*)p)->address=new char[strlen(adr)+1];
		strcpy( ((person*)p)->address,adr);
		addElem(m,p);
		delPerson(p);
	}
}
void printMapP(map m){
	TElem p;
	Iterator it;
	it=create(m);
	cout<<"(PIN , address)"<<endl;
	while (valid(it)) {
		p=elem(it);
		cout<<"("<<((person*)p)->PIN<<" , "<<((person*)p)->address<<")"<<endl;
		next(it);
	}
	destroyIt(it);
}
void searchByKeyP(map m){
	TElem p;
	int pin;
	bool found=false;
	Iterator it;
	
	it=create(m);
	cout<<"Give the key:";
	cin>>pin;
	
	while ((valid(it))&&(!found)){
		p=elem(it);
		if (((person*)p)->PIN==pin) {
			found=true;
			cout<<"The value coresponding to the key is: "<<((person*)p)->address<<endl;
		}
		next(it);
	}
	if (!found) cout<<"No value for the given key";
	destroyIt(it);
}
void main(){
	map m;
	//Word (ro,en)
	readMapW(m);
	printMapW(m);
	searchByKeyW(m);
	destroy(m);
	//Person (PIN,address)
	readMapP(m);
	printMapP(m);
	searchByKeyP(m);
	destroy(m);
	
	getch();
}
	

