//============================================================================
// Name        : AG6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <assert.h>

class Taietura{
public:
	std::vector<int> varfuri;
	int capacitate;
	Taietura(std::vector<int> a, int cap){
		this->varfuri = a;
		this->capacitate = cap;
	}
	~Taietura(){
		for(unsigned int i=0; varfuri.size(); i++){
			this->varfuri.erase(varfuri.begin());
		}
		this->capacitate = 0;
	}
};

void readMatrix(int **a, int nrEdges){
	int aux1, aux2, aux3;
	for (int i=0; i<nrEdges; i++){
		std::cout << "Introduceti extremitatea initiala a muchiei: ";
		std::cin >> aux1;
		std::cout << "Introduceti extremitatea finala a muchiei: ";
		std::cin >> aux2;
		std::cout << "Introduceti capacitatea muchiei: ";
		std::cin >> aux3;
		a[aux1-1][aux2-1] = aux3;
	}
}

int capacitate(int **a, int n, std::vector<int> varfuri){
	int c=0;
	bool ok;
	for(unsigned int i=0; i<varfuri.size(); i++){
		for(int j = 0; j<n; j++){
			ok = true;
			for(unsigned int k = 0; k<varfuri.size(); k++){
				if(j == varfuri[k]){
					ok = false;
				}
			}
			if(ok){
				c += a[varfuri[i]][j];
			}
		}
	}
	return c;
}

void back(int **a, int n, int q, int *vizit, std::vector<int> b, int *min, int source, int destination, std::vector<Taietura> *taimin){
	if(q == n){
		for(unsigned int i = 0; i<b.size(); i++){
			b.erase(b.begin());
		}
		for(int i=0; i<n; i++){
			if(vizit[i] == 1){
				b.push_back(i);
			}
		}
		Taietura *t = new Taietura(b, capacitate(a, n, b));
		taimin->push_back(*t);
		delete t;
	}else{
		if(q == source){
			vizit[q] = 1;
			back(a, n, q+1, vizit, b, min, source, destination, taimin);
		}else{
			if(q == destination){
			vizit[q] = 0;
			back(a, n, q+1, vizit, b, min, source, destination, taimin);
			}else{
				for(int j = 0; j<2; j++){
					vizit[q] = j;
					back(a, n, q+1, vizit, b, min, source, destination, taimin);
				}
			}
		}
	}
}

void taieturaMin(int **a, int n, int source, int destination, std::vector<Taietura> *taimin){
	int min, *vizit = new int[n];
	for(int i=0; i<n; i++){
		vizit[i] = 0;
	}
	std::vector<int> varfuri;
	back(a, n, 0, vizit, varfuri, &min, source, destination, taimin);
	delete[] vizit;
}

void findSrcDest(int **a, int n, int *source, int *destination){
		bool sfinder, dfinder;
		for(int i=0; i<n; i++){
			sfinder = true;
			dfinder = true;
			for(int j=0; j<n; j++){
				if(a[i][j]!=0){
					dfinder = false;
				}
				if(a[j][i]!=0){
					sfinder = false;
				}
			}
			if(sfinder){
				*source = i;
			}
			if(dfinder){
				*destination = i;
			}
		}
}

void teste(){
	int n = 4, m = 4, **a, src, dest;
	a = new int*[n];
	for(int i = 0; i<n; i++){
		a[i] = new int[n];
	}
	a[0][1] = 1;
	a[0][2] = 1;
	a[1][3] = 3;
	a[2][3] = 3;
	findSrcDest(a, n, &src, &dest);
	std::vector<Taietura> taimin;
	taieturaMin(a, n, src, dest, &taimin);
	int min = taimin[0].capacitate;
	for(unsigned int i=0; i<taimin.size(); i++){
		if(min > taimin[i].capacitate){
			min = taimin[i].capacitate;
		}
	}
	assert(min == 2);
	for(int i = 0; i<n; i++){
		delete[] a[i];
	}
	delete[] a;
}

int main() {
	teste();
	int m, n;
	int **a;
	std::cout << "Introduceti numarul de varfuri:";
	std::cin >> n;
	a = new int*[n];
	for(int i = 0; i<n; i++){
		a[i] = new int[n];
	}

	if(n>0){
		std::cout << "Introduceti numarul de muchii:";
		std::cin >> m;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				a[i][j]=0;
			}
		}
		readMatrix(a, m);
		int source, destination;
		findSrcDest(a, n, &source, &destination);

		std::cout <<"Sursa: " << source+1 << std::endl << "Destinatia:" << destination+1 << std::endl;
		std::vector<Taietura> taimin;
		taieturaMin(a, n, source, destination, &taimin);
		int pos = 0, min = taimin[0].capacitate;
		for(unsigned int i=0; i<taimin.size(); i++){
			if(min > taimin[i].capacitate){
				min = taimin[i].capacitate;
				pos = i;
			}
		}
		std::cout << "Varfurile care compun o taietura de capacitate minima sunt: ";
		for(unsigned int i = 0; i<taimin[pos].varfuri.size(); i++){
			std::cout << taimin[pos].varfuri[i] + 1 << " ";
		}
		std::cout << std::endl << "Capacitate: " << taimin[pos].capacitate;
	}
	for(int i = 0; i<n; i++){
			delete[] a[i];
	}
	delete[] a;
	return 0;
}
