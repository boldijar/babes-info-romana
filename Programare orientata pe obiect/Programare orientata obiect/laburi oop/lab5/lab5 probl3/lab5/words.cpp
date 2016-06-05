#include "Bag.h"
#include <string.h>
#include <iostream>
using namespace std;
struct Pair{
	char* word;
	char* syno;
	
};

void createPair(Pair *& p) // *
{
	p=new Pair;
	cout<<"Word= ";
	p->word=new char[20];
	cin>>p->word;
	cout<<"Synonim=";
	p->syno=new char[20];
	cin>>p->syno;
	cout<<endl;
}

int cmpPair(Telem e1, Telem e2){
	Pair p1=*(Pair*)e1;
	Pair p2=*(Pair*)e2;
    if ((strcmp(p1.word,p2.word)==0)&&(strcmp(p1.syno,p2.syno)==0)) 
		return 0;
    return 1; 
}

void cpyPair(Telem& e1, Telem e2){
	 e1=new Pair;
	 Pair * p2=(Pair*) e2;
	 Pair * p1=(Pair*) e1;
	 p1->word=new char[strlen(p2->word)+1];
	 strcpy(p1->word,p2->word);
	 p1->syno=new char[strlen(p2->syno)+1];
	 strcpy(p1->syno,p2->syno);
}

void delPair(Telem& e)
{
	Pair*p =(Pair*)e;
	delete[]p->word;
	delete[]p->syno;
	delete p;
}

void ReadBagPair(Bag& b)
{
	 init(b,cpyPair,cmpPair,delPair,20);
	 int n;
	 cout<<"Give the number of paris from the bag ";
	 cin>>n;
	 Telem e;
	 for(int i=0; i<n; i++)
	{
		Pair *p;
		createPair(p);
		e=p;
		add(b,e);
		delPair(e);
	}
}
void PrintBagPair(Bag b,int c)
{
	Iterator it;
	create(b,it);
	while(valid(it))
	{
		Pair *p= (Pair*)elem(it);
		cout<<p->word<<'='<<p->syno;
		if(c==1 )
		cout<<" appears " <<freqs(it)<<" times "<<endl;
		next(it);
	}
	//destroy(it);
}


int main(){
	Bag a,uniPair,intPair,intPair2;
	init(a,cpyPair,cmpPair,delPair,20);
	int no=1;
	init(uniPair,cpyPair,cmpPair,delPair,20);
	init(intPair,cpyPair,cmpPair,delPair,20);
	ReadBagPair(a);
	while(!empty(a))
	{
		uni(uniPair,a,uniPair);
		if(no==1)
		{
		inter(uniPair,a,intPair);
		no++;
		}
		else
		if(no>=2)
		{
			init(intPair2,cpyPair,cmpPair,delPair,20);
			inter(intPair,a,intPair2);
      
            no++;
			intPair=intPair2;
		}
		destroy(a);
		ReadBagPair(a);
	}
	destroy(a);
	cout<<"The union is "<<endl;
	PrintBagPair(uniPair,1);
    cout<<"The intersection is "<<endl;
	if(empty(intPair)==0)
		PrintBagPair(intPair,0);
	else
		cout<<" the empty bag ";
	system("pause");
}