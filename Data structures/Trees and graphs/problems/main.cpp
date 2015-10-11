#include "4_4.h"

int main()
{
	Tree<int> tree;
	tree.add(4);
	tree.add(1);
	tree.add(0);
	tree.add(6);
	tree.add(11);
	list<TreeNode<int> >* depthLists = tree.makeLists();

	return 0;
}
