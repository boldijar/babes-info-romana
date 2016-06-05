struct vector{int n;
       int *a;
};

void read(vector &v);
void print(vector v);
void release(vector & v);
void pos_seq_cons(vector v, int &p1,int &p2);
void del_seq(vector & v, int p1, int p2);
void del_all_seq(vector &v);
void merge(vector v1, vector v2, vector &v3);   //v3=v1+v
void insertion(vector &v, int x, int p);
void sort(vector &v);
int getElem(vector v, int i);
int getSize(vector v);
int compare(int x, int y);