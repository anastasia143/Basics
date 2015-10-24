#include <iostream>
#include "2_1.h"

int main()
{
	LinkedList<int> list;
	cout << "g";
	list.add(5);
	list.add(5);
	list.add(4);
	list.add(4);
	list.add(7);
	list.add(6);
	list.add(6);
	list.removeDuplicates2();
	list.print();

	return 0;
}
