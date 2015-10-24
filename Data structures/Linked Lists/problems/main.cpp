#include <iostream>
#include "2_2.h"

int main()
{
	LinkedList<int> list;
	cout << "g";
	list.add(5);
	list.add(3);
	list.add(4);
	list.add(7);
	cout << list.nthToLast(4);
	cout << list.nthToLast(3);

	return 0;
}
