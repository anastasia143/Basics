#pragma once
#include <queue>

/** 10.7 Design an algorithm to find the kth number such that the only
 * prime factors are 3, 5, and 7.
**/

using namespace std;

int product357(int k)
{
	if (k == 1)
		return 1;
	queue<int> queue1;
	queue1.push(3);

	queue<int> queue2;
	queue2.push(5);

	queue<int> queue3;
	queue3.push(7);

	int queueNum = 1;
	int counter = 2;
	int min = 0;
	while (counter >= 0) {
		min = queue1.front();
		queueNum = 1;
		if (min > queue2.front()) {
			min = queue2.front();
			queueNum = 2;
		}
		if (min > queue3.front()) {
			min = queue3.front();
			queueNum = 3;
		}
		if (counter == k)
			return min;
		switch (queueNum) {
		case 1:
			queue1.pop();
			queue1.push(min * 3);
			queue1.push(min * 5);
			queue1.push(min * 7);
			break;
		case 2:
			queue2.pop();
			queue2.push(min * 5);
			queue2.push(min * 7);
			break;
		case 3:
			queue3.pop();
			queue3.push(min * 7);
			break;
		default:
			break;
		}

		counter++;
	}
}
