#pragma once
#include <iostream>

using namespace std;

/** Linked List is an abstract data type that represents an ordered sequence of values,
 * where the same value may occur more than once.
 *          average | worst
 * add        O(1)     O(1)
 * remove     O(n)     O(n)
 * check      O(n)     O(n)
 * index      O(n)     O(n)
**/

template <typename T>
struct Node
{
	Node(int val)
		: value(val)
		, next(NULL) {}

	T value;
	Node* next;
};

template <typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void add(T value);
	void remove(T value);
	bool check(T value);

	void print();
private:
	Node<T>* root;
	int size;
};

template <typename T>
LinkedList<T>::LinkedList()
	: root(NULL)
	, size(0) {}

template <typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* temp = root;
	while (temp != NULL) {
		temp = root->next;
		delete root;
		root = temp;
	}
}

template <typename T>
void LinkedList<T>::add(T value)
{
	if (size == 0) {
		root = new Node<T>(value);
	} else {
		Node<T>* temp = root;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new Node<T>(value);
	}
	size++;
}

template <typename T>
void LinkedList<T>::remove(T value)
{
	if (size == 0)
		return;
	if (root->value == value) {
		Node<T>* temp = root->next;
		delete root;
		root = temp;
	}
	else {
		Node<T>* node = root;
		while (node->next != NULL) {
			if (node->next->value == value) {
				Node<T>* temp = node->next->next;
				delete node->next;
				node->next = temp;
			}
			else {
				node = node->next;
			}
		}
	}
	size--;
}

template <typename T>
bool LinkedList<T>::check(T value)
{
	Node<T>* node = root;
	while (node != NULL) {
		if (node->value == value)
			return true;
		node = node->next;
	}
	return false;
}

template <typename T>
void LinkedList<T>::print()
{
	Node<T>* node = root;
	while (node != NULL) {
		cout << node->value << " ";
		node = node->next;
	}
}
