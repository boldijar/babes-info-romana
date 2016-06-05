typedef int elem;
class List;

class Node //eliminam set si get; numai lista are dreptul de a modifica informatiile din nod.
{
private: elem inf;
		 Node* link;
public: Node()
		{
			inf=0;
			link=0;
		};

		Node(elem e)
		{
			inf=e;
			link=0; //NULL
		};

		elem getInf()
		{
			return inf;
		};

		Node* getLink()
		{
			return link;
		};
		void setInf(elem inf);
		void setLink(Node* link);
		~Node()
		{};
		friend class List;
}

void Node::setInf(elem inf)
{
	this->inf=inf;
}
void Node::setLink(Node* link)
{
	this->link=link;
}

class Iterator;
class List
{
private:
	Node* start;
public:
	List()
	{
		start=NULL;
	}
	~List();
	List(const List&);
	List& operator=(const List&);
	void addfirst(elem&);
	void insert(elem&,Position);
	void remove(Position);
	Position getFirstPos();
	Position getNextPos(Position);
	friend class Iterator;
	Iterator getIterator();
}

//list.cpp
//#include "list.h"
List::List(const List&)
{
	Position pos=start;
	if (start!=NULL) //cred?
	{
		p=new Node(pos->inf);
		start=p;
		pos=pos->link;
		while(pos!=NULL)
		{
			p->link=new Node(pos->inf);
			p=p->link;
			pos=pos->link;
		}
	}
	else
		start=NULL;
}

List::~List()
{
	Position pos.tmp;
	pos=start;
	while(pos!=NULL)
	{
		tmp=pos;
		pos=pos->link;
		delete tmp;
	}
}

List& List::operator=(const List& w)
{
	if(this!=&w)
	{
		Position pos,p;
		pos=start;
		while(pos!=NULL)
		{
			p=pos;
			pos=pos->link;
			delete p;
			l1=l2;
		}
	}
}

void List::addfirst(elem& e)
{
	start=new Node(e,start);
}

void List::insert(elem &e, Position w)
{
	w->link=new Node(e,w->link);