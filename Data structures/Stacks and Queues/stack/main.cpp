#include "stack.h"

int main()
{
	Stack<int> stack;
	stack.push(5);
	stack.push(7);
	stack.pop();
	stack.pop();
	stack.print();

	return 0;
}
