#include <iostream>
#include "linked_list.h"

int main()
{
	LinkedList<int>* list = new LinkedList<int>;
	list->add(4);
	list->add(10);
	list->add(5);
	list->add(16);
	list->remove(4);
	list->remove(5);
	list->remove(16);
	list->add(17);
	list->print();
	cout << list->check(16);
	cout << list->check(17);
	delete list;
	return 0;
}
