#pragma once
#include <cstddef>
#include <iostream>

/** Stack is a LIFO data structure. The term LIFO stems from the fact that, using these operations,
 * each element "popped off" a stack in series of pushes and pops is the last (most recent) element
 * that was "pushed into" within the sequence.
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
class Stack
{
public:
	Stack();
	~Stack();
	void push(T value);
	void pop();
	T top();

	void print();
private:
	Node<T>* root;
	int size;
};

template <typename T>
Stack<T>::Stack()
	: size(0)
	, root(NULL) {}

template <typename T>
void Stack<T>::push(T value)
{
	if (size == 0) {
		root = new Node<T>(value);
	} else {
		Node<T>* temp = root;
		root = new Node<T>(value);
		root->next = temp;
	}
	size++;
}

template <typename T>
Stack<T>::~Stack()
{
	Node<T>* temp = root;
	while(temp != NULL) {
		temp = root->next;
		delete root;
		root = temp;
	}
}

template <typename T>
void Stack<T>::pop()
{
	if (size == 1) {
		delete root;
		root = NULL;
	} else {
		Node<T>* temp = root->next;
		delete root;
		root = temp;
	}
	size--;
}

template <typename T>
T Stack<T>::top()
{
	return root->value;
}

template <typename T>
void Stack<T>::print()
{
	Node<T>* node = root;
	while(node != NULL) {
		cout << node->value << " ";
		node = node->next;
	}
}
