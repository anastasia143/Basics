#include <iostream>
#include "2_3.h"

using namespace std;

int main()
{
	/*LinkedList<int> list;
	cout << "g";
	list.add(5);
	list.add(3);
	list.add(4);
	list.add(7);
	cout << list.nthintoLast(4);
	cout << list.nthintoLast(3);*/

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
	return 0;
}
