#ifndef QUEUE_H
#define QUEUE_H
#include "telem.h"
struct _Queue;
typedef _Queue *Queue;
void init(Queue &,cpyFun,cmpFun,delFun,int=20);
void destroy(Queue);
void push(Queue,Telem);
Telem pop(Queue);
int sizeQ(Queue);
int isEmpty(Queue);
#endif
