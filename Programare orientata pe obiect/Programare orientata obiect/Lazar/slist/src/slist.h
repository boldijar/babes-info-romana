/*
 * slist.h
 *
 *  Created on: 11 Mar 2012
 *      Author: ilazar
 */

#ifndef SLIST_H_
#define SLIST_H_
#include <iostream>

template<typename E> class slist;
template<typename E> class slist_iterator;

template<typename E>
class Node {
private:
	E element;
	Node* next;
public:
	friend class slist<E>;
	friend class slist_iterator<E>;
	Node(E element, Node* next) {
		this->element = element;
		this->next = next;
	}
};

template<typename E>
class slist_iterator {
public:
	friend class slist<E>;
	slist_iterator(const slist_iterator& it) {
		this->_pointee = it._pointee;
	}
	slist_iterator& operator++();
	const E& operator*();
	bool operator != (slist_iterator<E>& other);
	~slist_iterator() { }
private:
	Node<E>* _pointee;
	slist_iterator(Node<E>* pointee) : _pointee(pointee) { }
};

template<typename E>
class slist {
private:
	int _size;
	Node<E>* _head;
public:
	typedef slist_iterator<E> iterator;
	slist() {
		_head = 0;
		_size = 0;
	}

	~slist();

	int size() {
		return _size;
	}

	void push_back(E e);

	void push_front(E e);

	iterator begin();

	iterator end();

	void insert_after(iterator& it, E e);
};

template<typename E>
slist<E>::~slist() {
	if (_head != 0) {
		delete _head;
	}
}

template<typename E>
void slist<E>::push_back(E e) {
	if (_head == 0) {
		_head = new Node<E>(e, _head);
	} else {
		Node<E>* p = _head;
		while (p->next != 0) {
			p = p->next;
		}
		p->next = new Node<E>(e, 0);
	}
}

template<typename E>
void slist<E>::push_front(E e) {
	_head = new Node<E>(e, _head);
}

template<typename E>
slist_iterator<E> slist<E>::begin() {
	return slist_iterator<E>(_head);
}

template<typename E>
slist_iterator<E> slist<E>::end() {
	return slist_iterator<E>(0);
}

template<typename E>
void slist<E>::insert_after(slist_iterator<E>& it, E e) {
	Node<E>* pointee = it._pointee;
	it._pointee = new Node<E>(e, pointee);
}

template<typename E>
slist_iterator<E>& slist_iterator<E>::operator++() {
	if (_pointee != 0) {
		_pointee = _pointee->next;
	}
	return *this;
}

template<typename E>
const E& slist_iterator<E>::operator*() {
	return _pointee->element;
}

template<typename E>
bool slist_iterator<E>::operator!=(slist_iterator<E>& other) {
	return _pointee != other._pointee;
}

#endif /* SLIST_H_ */
