#pragma once
#include <iostream>
#include <set>

/** 2.5 Given a circular linked list, implement an algorithm which
 * returns node at the beginning of the loop.
 *
 * DEFINITION
 * Circular linked list: A (corrupt) linked list in which a node’s next pointer
 * points to an earlier node, so as to make a loop in the linked list.
 *
 * EXAMPLE
 * Input: A -> B -> C -> D -> E -> C [the same C as earlier]
 * Output: C
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
	Node<T>* getRoot() { return root; }
	bool isEmpty() {return size == 0; }

	Node<T>* findLoopStart();

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
void LinkedList<T>::print()
{
	Node<T>* node = root;
	while (node != NULL) {
		cout << node->value << " ";
		node = node->next;
	}
}

template <typename T>
Node<T>* LinkedList<T>::findLoopStart() {
	Node<T>* temp1 = root;
	Node<T>* temp2 = root;

	// Find meeting point
	while (temp1 != temp2) {
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	/* Move n1 to Head. Keep n2 at Meeting Point. Each are k steps
	from the Loop Start. If they move at the same pace, they must
	meet at Loop Start. */
	temp1 = root;
	while (temp1 != temp2) {
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	// Now n2 points to the start of the loop.
	return temp2;

}
