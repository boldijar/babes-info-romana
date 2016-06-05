#include "slist.h"
#include <iostream>

int main() {
	slist<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	slist<int>::iterator it = a.begin();
	slist<int>::iterator end = a.end();
	while(it != end) {
		std::cout << *it << std::endl;
		++it;
	}
	return 0;
}
