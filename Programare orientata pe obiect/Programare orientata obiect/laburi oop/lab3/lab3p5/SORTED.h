# ifndef SORTED_H
# define SORTED_H

struct vector{
	int cap;
	int size;
	int* elem;
};

void init(vector&,int);
void sort(vector&);
int insert(vector&,int);
void merge(vector,vector,vector&);
void remove(vector&,int,int);
int elimin(vector&);
void destroy(vector&);

#endif

