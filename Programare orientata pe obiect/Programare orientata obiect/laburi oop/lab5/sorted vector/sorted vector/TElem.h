# ifndef TELEM_H
#define TELEM_h

typedef void* TElem;

typedef void(*cpyFun)(TElem &,TElem); 
typedef int(*cmpFun)(TElem,TElem); 
typedef void(*delFun)(TElem &);

#endif
