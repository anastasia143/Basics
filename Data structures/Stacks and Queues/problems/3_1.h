#pragma once
#include <cstddef>

/** 3.1 Describe how you could use a single array to implement three stacks.
 *
 * Approach 1:
 * Divide the array in three equal parts and allow the individual stack to grow in that limited space.
 *
 * Approach 2:
 * In this approach, any stack can grow as long as there is any free space in the array.
 * We sequentially allocate space to the stacks and we link new blocks to the previous block.
 * This means any new element in a stack keeps a pointer to the previous top element of that particular stack.
**/


class ThreeStacks
{
public:
	ThreeStacks(int stackLength)
		: stackLength(stackLength)
		, stackIndex1(0)
		, stackIndex2(stackLength)
		, stackIndex3(stackLength * 2)
	{
		array = new int[stackLength * 3];
	}

	~ThreeStacks()
	{
		delete [] array;
	}

	void push(int stackNum, int value)
	{
		if (stackIndex1 >= stackLength - 1 && stackIndex2 >= stackLength * 2 - 1 && stackIndex3 >= stackIndex3 * 3 - 1)
			return; // throw exception instead of this
		if (stackNum == 1) {
			array[++stackIndex1] = value;
		} else if (stackNum == 2) {
			array[++stackIndex2] = value;
		} else if (stackNum == 3) {
			array[++stackIndex3] = value;
		}
	}

	int pop(int stackNum)
	{
		if (stackIndex1 <= 0 && stackIndex2 <= stackLength && stackIndex3 <= stackIndex3 * 2)
			return 0; // throw exception instead of this
		int value = 0;
		if (stackNum == 1) {
			value = array[stackIndex1--];
		} else if (stackNum == 2) {
			value = array[stackIndex2--];
		} else if (stackNum == 3) {
			value = array[stackIndex3--];
		}
	}

	int top(int stackNum)
	{
		if (stackNum == 1) {
			return array[stackIndex1];
		} else if (stackNum == 2) {
			return array[stackIndex2];
		} else if (stackNum == 3) {
			return array[stackIndex3];
		}
	}
private:
	int* array;
	int stackLength;
	int stackIndex1;
	int stackIndex2;
	int stackIndex3;
};

class StackNode
{
public:
	int previous;
	int value;
	StackNode(int p = 0, int v = 0)
		: value(v)
		, previous(p) {}
};

class ThreeStacks2
{
public:
	ThreeStacks2(int stackSize)
		: stackSize(stackSize)
		, indexUsed(0)
	{
		stackPointer = new int[3];
		stackPointer[0] = -1;
		stackPointer[1] = -1;
		stackPointer[2] = -1;
		buffer = new StackNode[stackSize * 3];
	}

	~ThreeStacks2()
	{
		delete [] stackPointer;
		delete [] buffer;
	}

	void push(int stackNum, int value)
	{
		int lastIndex = stackPointer[stackNum];
		stackPointer[stackNum] = indexUsed;
		indexUsed++;
		buffer[stackPointer[stackNum]] = StackNode(lastIndex,value);
	}
	int pop(int stackNum)
	{
		int value = buffer[stackPointer[stackNum]].value;
		int lastIndex = stackPointer[stackNum];
		stackPointer[stackNum] = buffer[stackPointer[stackNum]].previous;
		buffer[lastIndex] = NULL;
		indexUsed--;
		return value;
	}
	int top(int stackNum)
	{
		return buffer[stackPointer[stackNum]].value;
	}
	bool isEmpty(int stackNum)
	{
		return stackPointer[stackNum] == -1;
	}

private:
	int stackSize;
	int indexUsed;
	int* stackPointer;
	StackNode* buffer;
};
