/*
 * TADMultime.h
 *
 *  Created on: Jun 7, 2012
 *      Author: Admin
 */

#ifndef TADMULTIME_H_
#define TADMULTIME_H_
#define CAPACITATE_MAXIMA 13

#include <iostream>
using namespace std;

template <typename TElement>
class IteratorMultime;

template<typename TElement>
class Multime{

	class Nod {
		public:
		TElement element;
		Nod* urmator;

	};

public:
	Multime();
	~Multime();
	void add(TElement element);     /* adds a (key,value) pair in the map; replaces the value if key already in the map */
	bool search(TElement element); /* searches for the key and returns its associated value and true if found, false otherwise */
	void remove(TElement element); /* removes a pair given by its key; returns the associated value and true if key found, false otherwise */
	bool isEmpty();
	int size();

	friend class IteratorMultime<TElement>;
		IteratorMultime<TElement> iterator() {return IteratorMultime<TElement>(this);}

private:
	int dim;
	typename Multime<TElement>::Nod* prim;
	int max;   /* hashtable size */
	Nod** ht; /* array of lists corresponding to each hashing position */
    int hashFunction(TElement element) {return element.hashCode() % max;} /* assume class K has a "hashCode()" method that returns an integer hash code for each key*/
    Nod* multime;
};



template<typename TElement>
class IteratorMultime {
public:
	IteratorMultime(Multime<TElement>* m);
	void next();
	bool valid();
	TElement element();
private:
	Multime<TElement>* multime;
	typename Multime<TElement>::Nod* crt;
};




template<typename TElement>
Multime<TElement>::Multime() {
	max = 13; 						/* initialize hashtable size with an appropriate value*/
	ht = new Nod*[max]; 			/* allocate hash table */
	for(int i = 0; i < max; i++)
	ht[i] = NULL;
}

template <typename TElement>
void Multime<TElement>::add(TElement element)
{
	int pos = hashFunction(element); /*compute position at which the entry will be hashed*/
	Nod* crt = ht[pos];
	while(crt != NULL && !(element == crt->element))
		crt = crt->urmator;
	if (crt != NULL)
	   return;
	else /*add a map entry with the given key and value*/
	{
		Nod* n = new Nod; /*add node at the beginning of the list corresponding to position pos*/
		n->element = element;
		n->urmator = ht[pos];
		ht[pos] = n;
	}
	dim++;
}

template <typename TElement>
bool Multime<TElement>::search(TElement element)
{
	int pos = hashFunction(element);
	Nod* crt = ht[pos];
	while(crt != NULL && !(element == crt->element)) /*search for the key (class K is assumed to have an appropriate overloading for "==") */
			crt = crt->urmator;
	if(crt != NULL)
	{
		return true;
	}
	return false;
}

template <typename TElement>
void Multime<TElement>::remove(TElement element)
{
	int pos = hashFunction(element);
		Nod* crt = ht[pos];
		// daca lista e vida nu facem nimic
		      if (ht[pos] == NULL)
		            return;

		      // daca este primul element, atunci
		      // il stergem si mutam capul
		      if (ht[pos]->element == element)
		      {
		            Nod* deSters = ht[pos];
		            ht[pos] = ht[pos]->urmator;
		            delete deSters;
		            dim--;
		            return;
		      }

		      // cautam predecesorul
		      Nod* elem = ht[pos];
		      while (elem->urmator != NULL && (elem->urmator->element) == element)
		            elem = elem->urmator;


		      // daca a fost gasit, atunci il stergem
		      if (elem->urmator != NULL)
		      {
		            // salvam referinta la elementul de sters
		            Nod* deSters = elem->urmator;

		            // scurcircuitam elementul
		            elem->urmator = elem->urmator->urmator;

		            // si il stergem
		            delete deSters;
		            dim--;
		      }

}

template <typename TElement>
int Multime<TElement>::size(){
	return dim;

}

template <typename TElement>
bool Multime<TElement>::isEmpty()
{
	return dim == 0 ;
}

template<typename TElement>
IteratorMultime<TElement>::IteratorMultime(Multime<TElement>* mul) {
	multime = mul;
	crt = mul->prim;
}

template<typename TElement>
bool IteratorMultime<TElement>::valid() {
	return crt != NULL;
}

template<typename TElement>
TElement IteratorMultime<TElement>::element() {
	return crt->element;
}

template<typename TElement>
void IteratorMultime<TElement>::next() {
	crt=crt->urmator;
}

#endif /* TADMULTIME_H_ */
