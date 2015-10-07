#pragma once
#include "stack.h"

/** 3.5 Implement a MyQueue class which implements a queue using two stacks.**/

class MyQueue
{
public:
	MyQueue()
		: correctForPush(true)
	{
		stack1 = new Stack<int>;
		stack2 = new Stack<int>;
	}
	~MyQueue()
	{
		delete stack1;
		delete stack2;
	}
	void enqueue(int value)
	{
		if (!correctForPush)
		{
			while(!stack2->isEmpty())
				stack1->push(stack2->pop());
		}
		stack1->push(value);
		correctForPush = true;
	}
	int dequeue()
	{
		if (correctForPush) {
			while(!stack1->isEmpty())
				stack2->push(stack1->pop());
		}
		correctForPush = false;
		return stack2->pop();
	}
	int size()
	{
		return stack1->getSize() + stack2->getSize();
	}

private:
	bool correctForPush;
	Stack<int>* stack1;
	Stack<int>* stack2;
};
