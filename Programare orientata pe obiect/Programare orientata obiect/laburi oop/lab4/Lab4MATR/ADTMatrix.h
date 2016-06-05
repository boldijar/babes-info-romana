struct _Matrix{
	int n;//square matrix of n order
	int **x;
};

void read(_Matrix &a);
void print(_Matrix a);
void Mimul(_Matrix a, _Matrix b,_Matrix & c);
int Mdet(_Matrix a);
void dispose(_Matrix &a);
     