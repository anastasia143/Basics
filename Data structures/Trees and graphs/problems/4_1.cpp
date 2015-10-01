#include "4_1.h"

template <typename T>
bool Tree<T>::isBalanced()
{
	return maxDepth(root) - minDepth(root) <= 1;
}

template <typename T>
int Tree<T>::maxDepth(TreeNode<T>* node)
{
	if (node == NULL)
		return 0;
	return 1 + max(maxDepth(node->left), maxDepth(node->right));
}

template <typename T>
int Tree<T>::minDepth(TreeNode<T>* node)
{
	if (node == NULL)
		return 0;
	return 1 + min(maxDepth(node->left), maxDepth(node->right));
}
