#include "Nod.h"
class ARBORE
{
private:	
	Nod nod[50];
	int len;
public:
	ARBORE();
	int getLen();
	void Len_up();
	void Len_down();
	void setLen(int);
	int Adauga(int);
	int Zap(int);
	void Init(int);
	void Eliminare(int);
	int getInd(int);
	int elimina(int);
	void Preordine(int);
	void Inordine(int);
	void Postordine(int);

};
