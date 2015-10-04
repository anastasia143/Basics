#pragma once
#include <iostream>
#include <cstddef>
#include <limits>

/** 3.2 How would you design a StackWithMin which, in addition to push and pop, also
 * has a function min which returns the minimum element? Push, pop and min
 * should all operate in O(1) time.
 *
 * Approach 1:
 * You can implement this by having each Node2 in the stack keep track of the minimum
 * beneath itself. Then, to find the min, you just look at what the top element thinks is the min.
**/

using namespace std;

template <typename T>
struct Node2
{
	Node2(int val)
		: value(val)
		, next(NULL)
		, locMin(INT_MAX) {}

	T value;
	Node2* next;
	T locMin;
};

template <typename T>
class StackWithMin
{
public:
	StackWithMin();
	~StackWithMin();
	void push(T value);
	void pop();
	T top();
	T getMin();

	void print();
private:
	Node2<T>* root;
	int size;
};

template <typename T>
StackWithMin<T>::StackWithMin()
	: size(0)
	, root(NULL) {}

template <typename T>
StackWithMin<T>::~StackWithMin()
{
	Node2<T>* temp = root;
	while(temp != NULL) {
		temp = root->next;
		delete root;
		root = temp;
	}
}

template <typename T>
void StackWithMin<T>::push(T value)
{
	if (size == 0) {
		root = new Node2<T>(value);
		root->locMin = value;
	} else {
		Node2<T>* temp = root;
		root = new Node2<T>(value);
		root->next = temp;
		if (root->next->locMin < value)
			root->locMin = root->next->locMin;
		else
			root->locMin = value;
	}
	size++;
}

template <typename T>
void StackWithMin<T>::pop()
{
	if (size == 1) {
		delete root;
		root = NULL;
	} else {
		Node2<T>* temp = root->next;
		delete root;
		root = temp;
	}
	size--;
}

template <typename T>
T StackWithMin<T>::top()
{
	return root->value;
}

template <typename T>
void StackWithMin<T>::print()
{
	Node2<T>* Node2 = root;
	while(Node2 != NULL) {
		cout << Node2->value << " ";
		Node2 = Node2->next;
	}
}

template <typename T>
T StackWithMin<T>::getMin()
{
	return root->locMin;
}
