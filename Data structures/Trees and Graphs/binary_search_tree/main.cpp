#include <iostream>
#include "tree.h"

int main()
{
	Tree<int> tree;
	tree.add(4);
	tree.add(1);
	tree.add(0);
	tree.add(6);
	tree.add(11);
	tree.breadthFirstSearch();
	cout << endl;
	tree.depthFirstSearch();

	return 0;
}
