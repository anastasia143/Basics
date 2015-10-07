#include "3_1.h"
#include "3_2.h"
#include "3_2_2.h"
#include "3_3.h"
#include "3_6.h"

int main()
{
	/*StackWithMin2<int> stack;
	stack.push(5);
	cout << stack.getMin() << endl;
	stack.push(3);
	cout << stack.getMin() << endl;
	stack.pop();
	cout << stack.getMin();*/
	Stack<int>* stack2 = new Stack<int>;
	stack2->push(1);
	stack2->push(6);
	stack2->push(3);
	stack2->push(5);
	stack2->push(2);
	stack2->push(4);
	Stack<int>* stack = sort(stack2);
	stack->print();


	return 0;
}
