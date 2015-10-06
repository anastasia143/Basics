#pragma once
#include "stack.h"

/** 3.3 Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
 * Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold.
 * Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks,
 * and should create a new stack once the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop()
 * should behave identically to a single stack (that is, pop() should return the same values as it would if there were just a single stack).
FOLLOW UP
 * Implement a function popAt(int index) which performs a pop operation on a specific sub-stack

**/

class SetOfStacks
{
public:
	SetOfStacks(int stackArrSize, int threshold)
		: mThreshold(threshold)
		, mStackArrSize(stackArrSize)
		, mStackCount(0)
	{
		stackArr = new Stack<int>[stackArrSize];
	}
	int push(int value)
	{
		if (stackArr[mStackCount].getSize() == mThreshold)
			mStackCount++;
		// if mStackCount more
		stackArr[mStackCount].push(value);
	}
	int pop()
	{
		if (stackArr[mStackCount].getSize() == 0)
			mStackCount--;
		return stackArr[mStackCount].pop();
	}
	~SetOfStacks()
	{
		delete [] stackArr;
	}
private:
	int mThreshold;
	Stack<int>* stackArr;
	int mStackArrSize;
	int mStackCount;
};
