#include "StdAfx.h"
#include "Multime.h"
#include "Iterator.h"

Multime::Multime(void)
{/*pre:--
   post: se intializeaza numarul de dispersie si se aloca spatiu pentru tabela de dispersie
         se umple tabela cu valoru NIL(cnp="None",nume="None",penume="None")
 */
	this->numarDispersie = DIM2;
	this->mult = new TElement[this->numarDispersie*sizeof(TElement)];
	TElement el ;
	for(int i=0; i < this->numarDispersie; ++i)
		this->mult[i] = el;
}

int Multime::dispersie(TElement el,int nrVerificare) {
	//pre: el de tip TElement
	//post returneaza rezultatul functiei de dispersie [(hashCode%numarDispersie) + nrVerificare]% numarDispersie
	
	return (el.hashCode() % this->numarDispersie  + nrVerificare) % this->numarDispersie;
	

}
void Multime::adauga(TElement elem) {
	/*pre:functia primeste un  TElement(client) 
	  post:va adauga in multime acel TElement(in cazul in care acest lucru este posibil)
		   -deoarece este vorba de o multime,elementul se va adauga doar daca el nu a mai
		    aparut in tabela
	*/

	if(this->cauta(elem.getCNP()) == -1) {

		
		bool gasit = false; //nu am gasit pozitia de adaugare
		int i = 0; //numarul de verificare
		int j;
		do {
			j = this->dispersie(elem,i); //j e locatia de verificat
			if(this->mult[j].getCNP().compare("None") == 0 || this->mult[j].getCNP().compare("Sters") == 0)  {
				this->mult[j] = elem;
				gasit = true;
			}
			else i++;
		
		}while( gasit == false && i < this->numarDispersie );

		if(i ==  this->numarDispersie )
			std::cout << "tabela este plina"<<std::endl;
		else
			std::cout << "Clientul a fost adaougat cu scces si are hashcode "<<elem.hashCode() <<std::endl;

	}
	else
		std::cout << "Elementul nu se poate adauga deoarece se duplica CNP-ul"<<std::endl;
}

int Multime::cauta(string cnp){
	//pre: functia primeste ca argument un string CNP
	//post: functia returneaza pozitia pe care a fost gasit elementul 
	//      cu CNP-ul respectiv sau -1 daca nu s-a gasit acesta in tabela

	TElement e = TElement(cnp,"",""); //folosesc acest element doar pentru a optine hashcode
	bool gasit = false; //nu am gasit pozitia de adaugare
	int i = 0; //numarul de verificare
	int j;
	do {
		j = this->dispersie(e,i); 
		if(this->mult[j].getCNP().compare(cnp)==0) {
			 gasit = true;
		}
		else i++;
		
	}while( gasit == false && this->mult[j].getCNP().compare("None")!=0  && i < this->numarDispersie);

	if (gasit == true )
		return j;
	else
		return -1;
}
void Multime::sterge(string cnp){
	/*pre: functia primeste un string-cnp
	  post:daca se gaseste un client cu acest cnp-acesta se va sterge
	       -stergerea se va face prin inlocuirea campurilor TElementului cu valoare Sters
	*/
	
	int pozitiaDeSters = this->cauta(cnp);
	if(pozitiaDeSters != -1) {

		this->mult[pozitiaDeSters].setCNP("Sters");
		this->mult[pozitiaDeSters].setNume("Sters");
		this->mult[pozitiaDeSters].setPrenume("Sters");
	}


}

int Multime::dimensiune() {
	/*pre:--
	  post:functia returneaza numarul de elemente valide(persoane) prezente in tabela
	*/
	int contor = 0;
	for(int i = 0 ;i < this->numarDispersie; ++i )
		if(this->mult[i].getCNP().compare("None")!=0 && this->mult[i].getCNP().compare("Sters")!=0)
			contor++;
	return contor;
}

bool Multime::vida() {
	/*pre:--
	  post:functia returneaza true in cazul in care tabela e vida
		   si false in caz contrar
	 */
	if(this->dimensiune() == 0)
		return true;
	return false;
	
}

Iterator Multime::Itr() {
	/*pre:--
	  post:functia returneaza un iterator pentru multime
	 */
	return Iterator(this);
}
Multime::~Multime(void)
{
	
	this->numarDispersie = 0;
	delete[]this->mult;

}