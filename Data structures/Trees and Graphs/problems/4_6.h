#pragma once
#include <cstddef>

/** 4.6 Design an algorithm and write code to find the first common ancestor of two nodes
 * in a binary tree. Avoid storing additional nodes in a data structure.
 * NOTE: This is not necessarily a binary search tree.
 *
 * Attempt #1:
 * If each node has a link to its parent, we could trace p and q’s paths up until they intersect.
 *
 * Attempt #2:
 * Alternatively, you could follow a chain in which p and q are on the same side.
 *
 * Attempt #3:
 *	For any node r, we know the following:
 *	1. If p is on one side and q is on the other, r is the first common ancestor.
 *	2. Else, the first common ancestor is on the left or the right side.
 * So, we can create a simple recursive algorithm called search that calls search(left side)
 * and search(right side) looking at how many nodes (p or q) are placed from the left side
 * and from the right side of the current node.
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
private:
	TreeNode* mRoot;
};

TreeNode* commonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q);
bool covers(TreeNode* root, TreeNode* p);

