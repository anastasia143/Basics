#pragma once
#include <algorithm>

/** 4.1 Implement a function to check if a tree is balanced. For the purposes of this question,
 * a balanced tree is defined to be a tree such that no two leaf nodes differ in distance
 * from the root by more than one.
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

	bool isBalanced();

protected:
	int count;

private:
	TreeNode<T>* root;

	int maxDepth(TreeNode<T>* node);
	int minDepth(TreeNode<T>* node);
	int height(TreeNode<T>* node);
};
