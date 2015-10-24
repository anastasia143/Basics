#pragma once

/** 2.3 Implement an algorithm to delete a node in the middle
 * of a single linked list, given only access to that node.
 * EXAMPLE
 * Input: the node ‘c’ from the linked list a->b->c->d->e
 * Result: nothing is returned, but the new linked list looks like a->b->d->e
 *
 * NOTE: This problem can not be solved if the node to be deleted is the last
 * node in the linked list. That’s ok—your interviewer wants to see you point
 * that out. You could consider marking it as dummy in that case. This is an
 * issue you should discuss with your interviewer.
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
bool deleteNode(Node<T>* node) {
	if (node->next == NULL)
		return false;
	node->value = node->next->value;
	Node<T>* pemp = node->next->next;
	delete node->next;
	node->next = pemp;
	return true;
}

void test() {
	Node<int>* temp3 = new Node<int>(2);
	temp3->next = NULL;

	Node<int>* temp2 = new Node<int>(3);
	temp2->next = temp3;

	Node<int>* temp = new Node<int>(4);
	temp->value = 4;
	temp->next = temp2;

	deleteNode(temp2);

	Node<int>* pemp = temp;
	while (temp != NULL) {
		cout << pemp->value << " ";
		pemp = pemp->next;
	}
}


