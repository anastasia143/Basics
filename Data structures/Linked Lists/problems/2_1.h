#pragma once
#include <iostream>
#include <set>

/** 2.1 Write code to remove duplicates from an unsorted linked list.
 * FOLLOW UP
 * How would you solve this problem if a temporary buffer is not allowed?
**/

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

	void removeDuplicates();
	void removeDuplicates2();
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

template <typename T>
void LinkedList<T>::removeDuplicates()
{
	set<T> uniqueNodes;
	Node<T>* temp = root;
	uniqueNodes.insert(root->value);

	while (temp->next != NULL) {
		if (uniqueNodes.find(temp->next->value) != uniqueNodes.end()) {
			Node<T>* pemp = temp->next->next;
			delete temp->next;
			temp->next = pemp;
			temp = temp->next;
		}
		else {
			uniqueNodes.insert(temp->next->value);
		}
	}
}

template <typename T>
void LinkedList<T>::removeDuplicates2()
{
	set<T> uniqueNodes;
	Node<T>* temp = root;
	uniqueNodes.insert(root->value);

	while (temp != NULL && temp->next != NULL) {
		bool isDuplicate = false;
		Node<T>* temp2 = root;
		while (temp2 != temp->next) {
			if (temp2->value == temp->next->value) {
				isDuplicate = true;
				break;
			}
			temp2 = temp2->next;
		}
		if (isDuplicate) {
			Node<T>* pemp = temp->next->next;
			delete temp->next;
			temp->next = pemp;
		}
		else {
			uniqueNodes.insert(temp->next->value);
		}
		temp = temp->next;
	}
}

