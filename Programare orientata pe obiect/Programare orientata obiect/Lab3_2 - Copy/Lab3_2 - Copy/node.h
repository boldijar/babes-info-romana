#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <string>

template <typename Element>


class Node
{
private:
	Element element;
	Node* next;
public:
	Node(Element e, Node* next)
	{
		this->element=e;
		this->next=next;
	}
	Element getElement()
	{
	    return element;
	}
	Node* getNext()
	{
	    return this->next;
	}
	void setNext(Node* newNext)
	{
	    this->next=newNext;
	}

	void setElement(Element e)
	{
	    this->element=e;
	}
};


#endif // NODE_H_INCLUDED
