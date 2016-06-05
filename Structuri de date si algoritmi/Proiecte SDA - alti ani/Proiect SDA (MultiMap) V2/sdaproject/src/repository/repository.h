/*
 * repository.h
 *
 *  Created on: 07.06.2012
 *      Author: Emilian
 */

#ifndef REPOSITORY_H_
#define REPOSITORY_H_

#include "../domain/multimap.h"

class Hotel{
private:
//	MultiMap *hotel;
//	MultiMapIterator *it;

public:
	MultiMap *hotel;
	MultiMapIterator *it;

	/*constructor*/
	Hotel();

	/*destructor. elibereaza memoria ocupata*/
	~Hotel();

	/*adauga in in dictionar cheie si valoare
	 * pre: camera Int, nume String,
	 * post: au fost adaugate in dictionar
	 * returneaza true daca s-a efectuat adaugarea, false daca nu
	 */
	bool add( int camera, string nume);

	/* post: in c se afla lista camerelor pline
	 * returneaza numarul camerelor pline
	 */
	int pline(int c[]);

	/*returneaza true daca se gaseste in dictionar
	 * elementul format din camera si client
	 */
	bool exist(int camera, string nume);

	/*pre: exista element camera: cheie, nume: valoare
	 * post: a fost sters elementul format din camera si numele trimise
	 */
	void leave(int camera, string nume);

	/* returneaza true daca in camera exista cel putin un client cazat
	 *  false daca nu
	 */
	bool cameraOcupata(int camera);

	/* pre: camera are cel putin un client cazat in ea
	 * post: clienti contine numele clientilor din camera
	 * returneaza numarul clientilor din camera
	 */
	int oameniCamera(int camera, string oa[]);

};


#endif /* REPOSITORY_H_ */
