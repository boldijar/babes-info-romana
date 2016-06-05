#ifndef TELEM_H
#define TELEM_H
typedef void* TElem;
typedef void(*copyFun)(TElem&,TElem);
typedef int(*cmpFun)(TElem,TElem);
typedef void(*delFun)(TElem&);
#endif