/*
 * repository.cpp
 *
 *  Created on: 07.06.2012
 *      Author: Emilian
 */

#include "repository.h"
Hotel::Hotel(){
	hotel = new MultiMap;
	it = new MultiMapIterator(hotel);
}

Hotel::~Hotel(){
	delete(hotel);
	delete(it);
}

/*adauga in in dictionar cheie si valoare
 * pre: cheie Int, valoare String,
 * post: au fost adaugate in dictionar
 * returneaza true daca s-a efectuat adaugarea, false daca nu
 */
bool Hotel::add( int camera, string nume){
	string v[M];
	if(hotel->valorile(camera,v) >= K)
		return false;
	return(hotel->adauga(camera,nume));
}

/* post: in c se afla lista camerelor pline
 * returneaza numarul camerelor pline
 */
int Hotel::pline(int c[]){
	string v[K];
	int che[M];
	int i;
	int nr = 0;
	int n = hotel->cheile(che);
	for ( i = 0; i < n; i++){
		if ( hotel->valorile(che[i],v) == 4 ){
			c[nr++] = che[i];
		}
	}
	return nr;
}


/*returneaza true daca se gaseste in dictionar
 * elementul format din camera si client
 */
bool Hotel::exist(int camera, string nume){
	if ( hotel->cauta(camera,nume) == -1 )
		return false;
	return true;
}

/*pre: exista element camera: cheie, nume: valoare
 * post: a fost sters elementul format din camera si numele trimise
 */
void Hotel::leave(int camera, string nume){
	hotel->sterge(camera,nume);
}

/* returneaza true daca in camera exista cel putin un client cazat
 *  false daca nu
 */
bool Hotel::cameraOcupata(int camera){
	int c[M];
	int n = hotel->cheile(c);
	for (int i = 0; i < n; i++)
		if ( c[i] == camera )
			return true;
	return false;
}

/* pre: camera are cel putin un client cazat in ea
 * post: clienti contine numele clientilor din camera
 * returneaza numarul clientilor din camera
 */
int Hotel::oameniCamera(int camera, string oa[]){
	return(hotel->valorile(camera,oa));
}




