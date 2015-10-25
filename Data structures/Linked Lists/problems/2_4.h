#pragma once
#include <iostream>
#include <set>

/** 2.4 You have two numbers represented by a linked list, where each node contains
 * a single digit. The digits are stored in reverse order, such that the 1’s digit
 * is at the head of the list. Write a function that adds the two numbers and returns
 * the sum as a linked list
 * EXAMPLE
 * Input: (3 -> 1 -> 5) + (5 -> 9 -> 2)
 * Output: 8 -> 0 -> 8
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

LinkedList<int>* addition(LinkedList<int>* num1, LinkedList<int>* num2) {
	LinkedList<int>* res = new LinkedList<int>;

	if (num1->isEmpty() || num2->isEmpty()) {
		return res;
	}

	Node<int>* temp1 = num1->getRoot();
	Node<int>* temp2 = num2->getRoot();

	int rest = 0;
	int sum = 0;
	while (temp1 != NULL && temp2 != NULL) {
		sum = temp1->value + temp2->value + rest;
		if (sum >= 10)
			rest = 1;
		else
			rest = 0;

		res->add(sum % 10);

		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	if (temp1 != NULL) {
		res->add(temp1->value + rest);
		temp1 = temp1->next;
		while (temp1 != NULL) {
			res->add(temp1->value);
			temp1 = temp1->next;
		}
	}
	else if (temp2 != NULL) {
		res->add(temp2->value + rest);
		temp2 = temp2->next;
		while (temp2 != NULL) {
			res->add(temp2->value);
			temp2 = temp2->next;
		}
	}
	return res;
}
