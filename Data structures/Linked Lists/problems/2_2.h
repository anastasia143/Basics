#pragma once
#include <iostream>
#include <set>

/** 2.2 Implement an algorithm to find the nth to last element of a singly linked list. **/

using namespace std;

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

	void print();

	T nthToLast(int n);
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
void LinkedList<T>::print()
{
	Node<T>* node = root;
	while (node != NULL) {
		cout << node->value << " ";
		node = node->next;
	}
}

// suggest that we have the nth elem
template <typename T>
T LinkedList<T>::nthToLast(int n)
{
	Node<T>* temp = root;
	Node<T>* pemp = root;
	for (int i = 1; i < n; i++) {
		pemp = pemp->next;
	}

	if (pemp == NULL) {
		return temp->value;
	}
	else {
		pemp = pemp->next;
	}
	while (pemp != NULL) {
		pemp = pemp->next;
		temp = temp->next;
	}
	return temp->value;
}
