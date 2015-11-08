#pragma once
#include <vector>
#include <string>

/** 8.5 Implement an algorithm to print all valid (e.g., properly opened and closed) combinations
 * of n-pairs of parentheses.
 *
 * EXAMPLE:
input: 3 (e.g., 3 pairs of parentheses)
output: ()()(), ()(()), (())(), ((()))
**/

using namespace std;

void brackets(string str, int balance, size_t left, size_t right, size_t n)
{
	if (balance < 0 || left > n || right > n)
		return;
	if (balance == 0 && left == n && right == n) {
		cout << str << endl;
		return;
	}
	brackets(str + "(", balance + 1, left + 1, right, n);
	brackets(str + ")", balance - 1, left, right + 1, n);
}


void brackets(int n)
{
	string str = "";
	brackets(str, 0, 0, 0, n);
}
