#include "13_3.h"

void test() {
	Shape* x = new Shape();
	x->circumference(); // prints "Circumference of Base Class"
	Shape* y = new Triangle();
	y->circumference(); // prints "Circumference of Triangle Class"
}
