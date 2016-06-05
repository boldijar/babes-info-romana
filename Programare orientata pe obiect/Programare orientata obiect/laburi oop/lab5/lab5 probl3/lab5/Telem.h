#ifndef TELEM_H
#define TELEM_H
typedef void *Telem;
typedef void(*cpyFun)(Telem &,Telem);
typedef int(*cmpFun)(Telem,Telem);
typedef void(*delFun)(Telem&);
#endif