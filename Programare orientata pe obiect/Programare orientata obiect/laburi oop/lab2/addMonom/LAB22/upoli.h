//interface
typedef struct 
	{ 
	  int gr;
	  int coef[30];
	}poli;
typedef struct 
	{
	 int c;
	 int d;
	}monom;
void init(poli &p);
void readm(monom &m);
void readp(poli &p);
void printp(poli p);
void addmonom(poli p,monom m,poli &s);


