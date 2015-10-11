#include "4_5.h"

TreeNode* Tree::inorderSucc(TreeNode* node)
{
	if (node != NULL) {
		if (node->right != NULL || node->parent == NULL) // head or right child
			return leftMostChild(node->right);
		if (node->parent->left == node)
			return node->parent;
		else {
			TreeNode* temp;
			temp = node->parent;
			while (node->parent != NULL) { // go upper
				temp = node->parent;
				if (temp->left == node)
					break;
				node = temp;
			}
			return temp;
		}
	}
	return NULL;
}

TreeNode* leftMostChild(TreeNode* node)
{
	if (node == NULL)
		return NULL;
	while (node->left != NULL)
		node = node->left;
	return node;
}
