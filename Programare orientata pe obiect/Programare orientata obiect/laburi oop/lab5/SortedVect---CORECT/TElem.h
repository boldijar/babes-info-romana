#ifndef TELEM_H
#define TELEM_H

typedef void *TElem;
TElem creeaza(char*);
int compare(TElem, TElem);
char* toString(TElem);
typedef void( *cpyFun)(TElem &,TElem);
typedef int( *cmpFun)(TElem,TElem);
typedef void( *delFun)(TElem&);

#endif;