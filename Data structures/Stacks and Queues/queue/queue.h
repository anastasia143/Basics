#pragma once
#include <cstddef>
#include <iostream>

using namespace std;

/** Queue is  First-In-First-Out (FIFO) data structure. In a FIFO data structure,
 * the first element added to the queue will be the first one to be removed.
**/

template <typename T>
struct Node
{
	Node(int val)
		: value(val)
		, next(NULL) {}

	T value;
	Node<T>* next;
};

template <typename T>
class Queue
{
public:
	Queue();
	~Queue();
	void enqueue(T val);
	T dequeue();

	void print();
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
};

template <typename T>
Queue<T>::Queue()
	: size(0)
	, head(NULL)
	, tail(NULL)
{
}

template <typename T>
Queue<T>::~Queue()
{
	Node<T>* temp = head;
	while (head != NULL) {
		temp = head->next;
		delete head;
		head = temp;
	}
}

template <typename T>
void Queue<T>::enqueue(T val)
{
	if (size == 0) {
		tail = new Node<T>(val);
		head = tail;
	} else {
		tail->next = new Node<T>(val);
		tail = tail->next;
	}
	size++;
}

template <typename T>
T Queue<T>::dequeue()
{
	T val = head->value;
	if (size == 1) {
		delete head;
		head = NULL;
		tail = NULL;
	} else {
		Node<T>* headNext = head->next;
		delete head;
		head = headNext;
	}
	size--;
	return val;
}

template <typename T>
void Queue<T>::print()
{
	Node<T>* node = head;
	while(node != NULL) {
		cout << node->value << " ";
		node = node->next;
	}
}


