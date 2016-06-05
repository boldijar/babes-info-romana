#include "Colectie.h"


Colectie::Colectie()
{
	cap = 15;
	nr_elem = 0;
	for(int i = 0; i<cap; i++)
		buckets[i] = 0;
}

int Colectie::hash(IElem* a)
{
	return (((Integer*)(a))->getValue()%cap);
}

void Colectie::add(IElem* a)
{
	int poz = this->hash(a);
	Nod* nou = new Nod(a);

	
	if(buckets[poz]==NULL)
	{
		buckets[poz] = nou;
	}
	else
	{
		Nod* curent = buckets[poz];
		while(curent->next != 0)
			curent = curent->next;
		curent->next = nou;
	}
	nr_elem++;
}	

void Colectie::print()
{
	for (int i=0; i<this->cap; i++)
	{
		std::cout << i << ".\t";
		if (buckets[i]==NULL)
			std::cout << "EMPTY\n";
		else
		{
			Nod* aux = buckets[i];
			while(aux)
			{
				aux->info->print();
				if (aux->next!=NULL) 
					std::cout << " -> ";
				aux = aux->next;
			}
			std::cout << std::endl;
		}
	}
}

int Colectie::search(IElem* de_cautat)
{
	for (int i = 0; i<cap; i++)
	{
		if (buckets[i]==0)
			continue;
		if (buckets[i]->info->comparesTo(de_cautat)==0)
			return i;
		else
		{	
			Nod* aux = buckets[i];
			while(aux)
			{
				if(aux->info->comparesTo(de_cautat)==0)
					return i;
				aux = aux->next;
			}
		}
	}
	return -1; //daca nu s-a gasit elementul
}


int Colectie::remove(IElem* de_sters)
{
	int poz = this->search(de_sters);
	if (poz==-1)
		return -1; // nu s-a gasit elementul
	else
	{
		if(buckets[poz]->info->comparesTo(de_sters)==0) // daca e pe prima pozitie
		{
			if(buckets[poz]->next==NULL) // verificam daca nu cumva e singurul element din lista
			{
				delete buckets[poz];
				buckets[poz] = NULL;
				return 0;
			}
			else
			{
				Nod* del = buckets[poz];
				buckets[poz] = buckets[poz]->next;
				delete del;
				return 0;
			}
		}
		else // nu e pe prima pozitie
		{
			Nod* anterior = buckets[poz];
			Nod* curent = buckets[poz]->next;
			while(curent)
			{
				if(curent->info->comparesTo(de_sters)==0)
				{
					anterior->next = curent->next;
					delete curent;
					return 0;
				}
				anterior = curent;
				curent = curent->next;
			}
		}
	}
}

int Colectie::getNr_elem()
{
	return this->nr_elem;
}

Colectie::~Colectie()
{
}
