/*
 * TElement.h
 *
 *  Created on: 3 Jun 2014
 *      Author: Mihai
 */

#ifndef TELEMENT_H_
#define TELEMENT_H_

using namespace std;

class TElement {
public:
    string chei;
    string valori;

	string getChei(){
		//post:returneaza string
		return this->chei;
	}

	string getValori(){
		//post: returneaza string
		return this->valori;
	}

	void setValori(string def){
		//pre:def ->string
		this->valori = def;
	}

	void setChei(string cuv){
		//pre: cuv ->string
		this->chei = cuv;
	}

	TElement(){
		//constructor implicit
		this->chei="None";
		this->valori="None";
	}
    TElement(string cuv,string def){
    	//constructor
    	this->chei=cuv;
    	this->valori=def;
    }
    virtual ~TElement(){
    	//destructor
    	this->chei = "None";
    	this->valori = "None";
    }
    int hashCode(){
    	//post:returneaza codul ascii al primului caracter din chei
    	return (int)this->chei[0];
    }

    TElement *cmp(TElement* e){
    	//pre: e este de tip TElement
    	//post:returneaza elementul cu campul chei mai mic din punct de vedere lexicografic
    	if ((this->chei.compare(e->chei)) < 0)
    	{
    		TElement *el = new TElement(this->chei,this->valori);
    		return el;
    	}
    	else
    		return e;
    }

    friend ostream &operator<<(ostream &out, TElement *e)     //output
    	{
    	        return out << e->chei << " = " << e->valori <<"\n";
    	}

};

#endif /* TELEMENT_H_ */
