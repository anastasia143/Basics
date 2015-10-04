#pragma once
#include <iostream>
#include <cstddef>
#include "stack.h"

/** 3.2 How would you design a StackWithMin2 which, in addition to push and pop, also
 * has a function min which returns the minimum element? Push, pop and min
 * should all operate in O(1) time.
 *
 * Approach 2:
 * We can (maybe) do a bit better than this by using an additional stack which keeps track of the mins.
**/

using namespace std;

template <typename T>
struct Node3
{
	Node3(int val)
		: value(val)
		, next(NULL) {}

	T value;
	Node3* next;
};

template <typename T>
class StackWithMin2
{
public:
	StackWithMin2();
	~StackWithMin2();
	void push(T value);
	void pop();
	T top();
	T getMin();

	void print();
private:
	Node3<T>* root;
	int size;
	Stack<T> stackOfMin;
};

template <typename T>
StackWithMin2<T>::StackWithMin2()
	: size(0)
	, root(NULL) {}

template <typename T>
StackWithMin2<T>::~StackWithMin2()
{
	Node3<T>* temp = root;
	while(temp != NULL) {
		temp = root->next;
		delete root;
		root = temp;
	}
}

template <typename T>
void StackWithMin2<T>::push(T value)
{
	if (size == 0) {
		root = new Node3<T>(value);
		stackOfMin.push(value);
	} else {
		Node3<T>* temp = root;
		root = new Node3<T>(value);
		root->next = temp;
		if (value <= getMin())
			stackOfMin.push(value);
	}
	size++;
}

template <typename T>
void StackWithMin2<T>::pop()
{
	if (stackOfMin.top() == root->value)
		stackOfMin.pop();
	if (size == 1) {
		delete root;
		root = NULL;
	} else {
		Node3<T>* temp = root->next;
		delete root;
		root = temp;
	}
	size--;
}

template <typename T>
T StackWithMin2<T>::top()
{
	return root->value;
}

template <typename T>
void StackWithMin2<T>::print()
{
	Node3<T>* Node3 = root;
	while(Node3 != NULL) {
		cout << Node3->value << " ";
		Node3 = Node3->next;
	}
}

template <typename T>
T StackWithMin2<T>::getMin()
{
	return stackOfMin.top();
}
