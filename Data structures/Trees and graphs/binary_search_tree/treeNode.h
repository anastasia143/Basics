#pragma once

template <typename T>
struct TreeNode
{
	T value;
	int count;
	TreeNode *left;
	TreeNode *right;
};

template <typename T>
TreeNode<T>* createTreeNode(T element)
{
	TreeNode<T> *node = new TreeNode<T>;
	node->left = NULL;
	node->right = NULL;
	node->value = element;
	node->count = 1;
	return node;
}

// These functions are used in removing value from tree,
// but are not part of direct tree functional.
template <typename T>
TreeNode<T>* &leftMostChild(TreeNode<T>* &node)
{
	if (node->left != NULL)
		return leftMostChild(node->left);
	return node;
}

template <typename T>
bool hasNoChild(TreeNode<T>* node)
{
	return (node->left == NULL) && (node->right == NULL);
}

template <typename T>
bool hasOneChild(TreeNode<T>* node)
{
	return ((node->left == NULL) && (node->right != NULL)) ||
			((node->left != NULL) && (node->right == NULL));
}
