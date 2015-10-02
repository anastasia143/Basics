#pragma once
#include <cstddef>

/** 4.5 Write an algorithm to find the ‘next’ node (e.g., in-order successor)
 * of a given node in a binary search tree where each node has a link to its parent.
**/

struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
};

class Tree
{
public:
	TreeNode* inorderSucc(TreeNode* node);
private:
	TreeNode* mRoot;
};

TreeNode* leftMostChild(TreeNode* node);
