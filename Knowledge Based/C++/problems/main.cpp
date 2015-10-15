#include <iostream>
#include "13_6.h"
#include "13_1.h"
#include "13_9.h"
using namespace std;


int main()
{
	Expression* expr= new Expression(5);
	SharedPtr sp(expr);
//	f(sp);
	cout << sp.get() << " ";


	return 0;
}
