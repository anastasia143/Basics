#pragma once
#include <iostream>

using namespace std;

/** 13.3 How do virtual functions work in C++?
 * =============================================
 * A virtual function depends on a “vtable” or “Virtual Table”. If any function of a class
 * is declared as virtual, a v-table is constructed which stores addresses of the virtual
 * functions of this class. The compiler also adds a hidden vptr variable in all such classes
 * which points to the vtable of that class. If a virtual function is not overridden in the
 * derived class, the vtable of the derived class stores the address of the function in his
 * parent class. The v-table is used to resolve the address of the function, for whenever the
 * virtual function is called. Dynamic binding in C++ is therefore performed through the
 * vtable mechanism.
**/

class Shape {
public:
	int edge_length;
	virtual int circumference () {
		cout << "Circumference of Base Class\n";
		return 0;
	}
};

class Triangle: public Shape {
public:
	int circumference () {
	cout << "Circumference of Triangle Class\n";
		return 3 * edge_length;
	}
};

void test();

