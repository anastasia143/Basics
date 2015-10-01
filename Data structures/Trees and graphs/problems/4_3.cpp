#include "4_3.h"

void createMinimalBstFromArray(int* arr, int size)
{
	Tree<int>* tree;
	createMinimalBstFromArray(tree, arr, 0, size - 1);
}

void createMinimalBstFromArray(Tree<int>* tree, int* arr, int a, int b)
{
	if (a < b)
		return;
	int middle = (a + b) / 2;
	tree->add(middle);
	createMinimalBstFromArray(tree, arr, a, middle - 1);
	createMinimalBstFromArray(tree, arr, middle + 1, b);
}
