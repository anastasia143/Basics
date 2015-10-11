#pragma once
#include <cstddef>

/** 4.3 Given a sorted (increasing order) array, write an algorithm
 * to create a binary tree with minimal height.
**/

template <typename T>
struct TreeNode
{
	T value;
	int count;
	TreeNode *left;
	TreeNode *right;
};

template <typename T>
class Tree
{
public:
	Tree() : root(NULL), count(0) {}
	~Tree() {}

	add(int value) {}

protected:
	int count;

private:
	TreeNode<T>* root;
};

void createMinimalBstFromArray(int* arr, int size);
void createMinimalBstFromArray(Tree<int>* tree, int* arr, int a, int b);
