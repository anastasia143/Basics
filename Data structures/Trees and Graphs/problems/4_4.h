#pragma once
#include <iostream>
#include <set>
#include <queue>
#include <list>
#include "treenode.h"
using namespace std;

/** 4.4 Given a binary search tree, design an algorithm which creates a linked list of all
 * the nodes at each depth (eg, if you have a tree with depth D, you’ll have D linked lists).
**/

template <typename T>
class Tree
{
public:
	Tree() : root(NULL), count(0) {}
	~Tree();
	void deleteTree(TreeNode<T>* temp);
	int returnCount() { return count; }
/**
Direct functional
*/
	void add(T value);
	void remove(T value);
	bool exist(T value) const;
	int getElementCount(T value);

	list<TreeNode<T> >* makeLists();

protected:
	int count;

private:
	int breadthFirstSearchHelper(queue<pair<TreeNode<T>*,int> >* &vertexQueue, list<TreeNode<T> > *depthLists);
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
Tree<T>::~Tree()
{
	deleteTree(root);
}


template <typename T>
list<TreeNode<T> >* Tree<T>::makeLists()
{
	queue<pair<TreeNode<T>*,int> >* vertexQueue = new queue<pair<TreeNode<T>*,int> >;
	vertexQueue->push(make_pair(root, 0));

	list<TreeNode<T> > depthLists[1000];

	int depth = breadthFirstSearchHelper(vertexQueue, depthLists);

	delete vertexQueue;

	for (int i = 0; i < depth; i++) {
		for (TreeNode<T> &node : depthLists[i]) {
			cout << node.value << " ";
		}
		cout << endl;
	}

	return depthLists; // It`s much better to return depth too
}

template <typename T>
int Tree<T>::breadthFirstSearchHelper(queue<pair<TreeNode<T>*,int> >* &vertexQueue, list<TreeNode<T> >* depthLists)
{
	int depth = 0;
	while (!vertexQueue->empty()) {
		pair<TreeNode<T>*,int> headPair = vertexQueue->front();
		TreeNode<T>* vertex = headPair.first;
		vertexQueue->pop();
		depthLists[headPair.second].push_back(*vertex);
		depth = headPair.second + 1;
		if (vertex->left != NULL)
			vertexQueue->push(std::make_pair(vertex->left, depth));
		if (vertex->right != NULL)
			vertexQueue->push(std::make_pair(vertex->right, depth));
	}
	return depth;
}

