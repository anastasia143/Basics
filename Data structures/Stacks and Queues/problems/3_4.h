#pragma once
#include "stack.h"

using namespace std;

/** 3.4 In the classic problem of the Towers of Hanoi, you have 3 rods and N disks of different
 * sizes which can slide onto any tower. The puzzle starts with disks sorted in ascending order
 * of size from top to bottom (e.g., each disk sits on top of an even larger one). You have the
 * following constraints:
(A) Only one disk can be moved at a time.
(B) A disk is slid off the top of one rod onto the next rod.
(C) A disk can only be placed on top of a larger disk.
 * Write a program to move the disks from the first rod to the last using Stacks.
**/

class Tower {
public:
	Tower()
	{
		disks = new Stack<int>;
		index = 0;
	}
	void setIndex(int newIndex) { index = newIndex; }
	int getIndex() { return index; }

	void add(int d)
	{
		if (!disks->isEmpty() && disks->top() <= d) {
			cout << "Error placing disk " << d << endl;
		} else {
			disks->push(d);
		}
	}
	void moveTopTo(Tower &t)
	{
		int top = disks->pop();
		t.add(top);
		cout << "Move disk " << top << " from " << this->getIndex() << " to " << t.getIndex() << endl;
	}
/*	void print()
	{
		cout << "Contents of Tower " + getIndex();
		for (int i = disks->size() - 1; i >= 0; i--) {
		cout << " " + disks->get(i);
		}
	}*/
	void moveDisks(int n, Tower &destination, Tower &buffer)
	{
		if (n > 0) {
			moveDisks(n - 1, buffer, destination); // to this
			moveTopTo(destination);
			buffer.moveDisks(n - 1, destination, *this); // and reverse
		}
	}
private:
	Stack<int>* disks;
	int index;
};

void test()
{
	int n = 5;
	Tower* towers = new Tower[n];
	for (int i = 0; i < 3; i++)
		towers[i].setIndex(i);
	for (int i = n - 1; i >= 0; i--)
		towers[0].add(i);
	towers[0].moveDisks(n, towers[2], towers[1]);
}
