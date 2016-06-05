#include "queue.h"
struct _Queue
{
	Telem *order;
	int cap,card;
    cpyFun cpy;
	cmpFun cmp;
	delFun del;
};

void init(Queue &q,cpyFun cpy,cmpFun cmp,delFun del,int c)
{
	q=new _Queue;
	q->order=new Telem[c];
	q->cap=c;
	q->card=-1;
	q->cpy=cpy;
	q->cmp=cmp;
	q->del=del;
}
void destroy(Queue q)
{
	for(int i=0; i<=sizeQ(q); i++)
		q->del(q->order[i]);
	delete [] q->order;
	delete q;
}

void resize(Queue q)
{
	Telem * temp=new Telem[(q->cap)*2];
	for(int i=0; i<=sizeQ(q); i++)
		temp[i]=q->order[i];
	delete []q->order;
	q->order=temp;
	q->cap*=2;
}
void push(Queue q,Telem ord)
{
	if(isEmpty(q))
	{
		q->card++;
		q->cpy(q->order[q->card],ord);
	}
	else
	{
		int i=0;
		while((i<=sizeQ(q)) && (q->cmp(q->order[i],ord)==-1))
			i++;
		if(i==(sizeQ(q)+1))
		{
			if(q->card==q->cap)
				resize(q);
			q->cpy(q->order[++q->card],ord);
		}
		else
		{
			if(q->card==q->cap)
				resize(q);
			for(int j=sizeQ(q)+1; j>i; j--)
				q->order[j]=q->order[j-1];
			q->card++;
			q->cpy(q->order[i],ord);
			
		}
			
	}
}

Telem pop(Queue q)
{
	return q->order[q->card--];
}

int sizeQ(Queue q)
{
	return q->card;
}

int isEmpty(Queue q)
{
	return (q->card==-1);
}





