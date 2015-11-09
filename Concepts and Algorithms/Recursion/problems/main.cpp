#include <iostream>
#include "8_1.h"
#include "8_3.h"
#include "8_4.h"
#include "8_5.h"
#include "8_6.h"
#include "8_7.h"

int main()
{
	string str;
	str = "abc";
	vector<string> res = getPerms(str);
	for (string &str : res) {
		cout << str << endl;
	}
	return 0;
}
