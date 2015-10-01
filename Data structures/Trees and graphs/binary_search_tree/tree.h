#pragma once
#include <iostream>
#include "treeNode.h"
using namespace std;

/**
 * @brief The BinarySearchTree class
 * BST is a rooted binary tree with properties:
 * 1) Left and right subtrees are binary search trees.
 * 2) All nodes of the left subtree is less than the node X.
 * 3) All nodes of the right subtree is greater than the node X.
 *
 *        average  | worst case
 * space  O(n)     | O(n)
 * find   O(log n) | O(n)
 * add    O(log n) | O(n)
 * remove O(log n) | O(n)
 */

template <typename T>
class Tree
{
public:
	Tree() : root(NULL), count(0) {}
	~Tree();
	void deleteTree(TreeNode<T>* temp);
	void clear();
	int returnCount() { return count; }
/**
Direct functional
*/
	void add(T value);
	void remove(T value);
	bool exist(T value) const;
	int getElementCount(T value);

/**
Print functions that use defferent tree traversals
*/
	void preOrder();
	void inOrder();
	void postOrder();

protected:
	int count;

private:
	TreeNode<T>* root;

/**
Helping recursive functions
*/
	void add(TreeNode<T>* &node, T value);
	bool remove(TreeNode<T>* &node, T value);
	bool exist(TreeNode<T>* node, T value) const;
	void findEven(TreeNode<T>* node) const;
	int getElementCount(TreeNode<T>* &node, T value);

	void preOrder(TreeNode<T>* node);
	void inOrder(TreeNode<T>* node);
	void postOrder(TreeNode<T>* node);

};

template <typename T>
void Tree<T>::add(T value)
{
	add(root, value);
	count++;
}

template <typename T>
void Tree<T>::add(TreeNode<T>* &node, T value)
{
	if (node == NULL) {
		node = createTreeNode(value);
		return;
	}
	if (value < node->value)
		add(node->left, value);
	else if (value > node->value)
		add(node->right, value);
	else
		node->count++;
}

template <typename T>
bool Tree<T>::exist(T value) const
{
	if (count == 0)
		return false;
	if (root->value == value)
		return true;
	return exist(root, value);
}

template <typename T>
bool Tree<T>::exist(TreeNode<T>* node, T value) const
{
	if (node == NULL)
		return false;
	if (node->value == value)
		return true;
	if (value < node->value)
		return exist(node->left, value);
	else
		return exist(node->right, value);
}

template <typename T>
int Tree<T>::getElementCount(T value)
{
	if (!exist(value))
		return 0;
	else
		return getElementCount(root, value);
}

template <typename T>
int Tree<T>::getElementCount(TreeNode<T>* &node, T value)
{
	if (node->value == value)
		return node->count;
	if (value < node->value)
		return getElementCount(node->left, value);
	else
		return getElementCount(node->right, value);
}

template <typename T>
void Tree<T>::remove(T value)
{
	if (remove(root, value)) {
		count--;
	}
	else
		cout << "There is no this element in the tree." << endl;
}

template <typename T>
bool Tree<T>::remove(TreeNode<T>* &node, T value)
{
	if (value < node->value)
		remove(node->left, value);
	else if (value > node->value)
		remove(node->right, value);
	else if (node->count > 1) {
		node->count--;
		return true;
	}
	else if (hasNoChild(node)) {
		delete node;
		node = NULL;
		return true;
	}
	else if (hasOneChild(node)) {
		if (node->left != NULL) {
			TreeNode<T> *temp = node->left;
			delete node;
			node = temp;
			return true;
		}
		if (node->right != NULL) {
			TreeNode<T> *temp = node->right;
			delete node;
			node = temp;
			return true;
		}
	}
	else {
		if (node->right->left == NULL) {
			TreeNode<T>* left = node->left;
			TreeNode<T>* right = node->right;
			delete node;
			node = right;
			node->left = left;
			return true;
		} else {
			TreeNode<T>* &leftChild = leftMostChild(node->right);
			node->value = leftChild->value;
			return remove(leftChild, leftChild->value);
		}
	}
	return false;
}

template <typename T>
void Tree<T>::preOrder()
{
	preOrder(root);
}

template <typename T>
void Tree<T>::inOrder()
{
	inOrder(root);
}

template <typename T>
void Tree<T>::postOrder()
{
	postOrder(root);
}

template <typename T>
void Tree<T>::preOrder(TreeNode<T>* node)
{
	if (node == NULL)
		return;
	cout << node->value << "/" << node->count << " ";
	preOrder(node->left);
	preOrder(node->right);
}

template <typename T>
void Tree<T>::inOrder(TreeNode<T>* node)
{
	if (node == NULL)
		return;
	inOrder(node->left);
	cout << node->value << "/" << node->count << " ";
	inOrder(node->right);
}

template <typename T>
void Tree<T>::postOrder(TreeNode<T>* node)
{
	if (node == NULL)
		return;
	postOrder(node->left);
	postOrder(node->right);
	cout << node->value << "/" << node->count << " ";
}

template <typename T>
void Tree<T>::deleteTree(TreeNode<T>* temp)
{
	TreeNode<T> *node = temp;
	if (node != NULL)
	{
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}

template <typename T>
void Tree<T>::clear()
{
	deleteTree(root);
	root = NULL;
	count = 0;
}

template <typename T>
Tree<T>::~Tree()
{
	deleteTree(root);
}
