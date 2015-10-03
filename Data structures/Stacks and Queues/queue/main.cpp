#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
	Queue<int> queue;
	queue.enqueue(7);
	queue.enqueue(8);
	queue.enqueue(58);
	queue.print();
	cout << endl;
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	queue.print();

	return 0;
}
