#include "4_6.h"

TreeNode* commonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (covers(root->left, p) && covers(root->left, q))
		return commonAncestor2(root->left, p, q);
	if (covers(root->right, p) && covers(root->right, q))
		return commonAncestor2(root->right, p, q);
	return root;
}

bool covers(TreeNode* root, TreeNode* p) // is p a child of root?
{
	if (root == NULL)
		return false;
	if (p == root)
		return true;
	else
		return covers(root->left, p) || covers(root->right, p);
}

