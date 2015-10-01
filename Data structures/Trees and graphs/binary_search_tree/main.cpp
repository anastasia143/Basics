#include <iostream>
#include "tree.h"

int main()
{
	Tree<int> tree;
	tree.add(4);
	tree.add(0);
	tree.add(6);
	tree.add(11);
	tree.remove(4);
	tree.inOrder();

	return 0;
}
