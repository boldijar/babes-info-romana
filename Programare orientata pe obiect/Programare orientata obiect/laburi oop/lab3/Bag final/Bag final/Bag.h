# ifndef SET_H
# define SET_H
# include "TElem.h"

struct Set 
		{
			int card; int capacity;
			TElem * elem;
			int * occ;
		};
struct Iterator
		{
			Set * s;
			int crt;
		};
void init(Set &, int=20);
void add(Set &, TElem);
int belongs(Set, TElem);
int cart(Set);
Set Union1(Set,Set);
Set Intersection(Set,Set);
Set MostElem(Set,Set);
TElem * to_array(Set);
Iterator create(Set);
void next(Iterator);
TElem elem(Iterator);
int valid(Iterator);
void destroy(Set &);

#endif
