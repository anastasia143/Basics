#pragma once
#include "stack.h"

/** 3.6 Write a program to sort a stack in ascending order. You should not make
 * any assumptions about how the stack is implemented. The following are the only
 * functions that should be used to write this program: push | pop | peek | isEmpty.
**/

Stack<int>* sort(Stack<int>* stack)
{
	Stack<int>* stackTwo = new Stack<int>;
	while (!stack->isEmpty() ) {
		int temp = stack->pop();
		while(!stackTwo->isEmpty() && temp < stackTwo->top()) {
			stack->push(stackTwo->pop());
		}
		stackTwo->push(temp);
	}
	return stackTwo;
}
