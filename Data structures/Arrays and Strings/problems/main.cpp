#include <iostream>
#include "1_1.h"
#include "1_2.h"
using namespace std;

int main()
{
	char str[6] = "abcde";
	reverse(str);
	cout << str;
	reverse2(str);
	cout << str;
	return 0;
}
