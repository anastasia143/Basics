#pragma once
#include <iostream>

/** 8.1 Write a method to generate the nth Fibonacci number. **/

using namespace std;

size_t fib1(size_t n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fib1(n - 1) + fib1(n - 2);
}

size_t fib2(size_t n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	size_t prev = 0;
	size_t cur = 1;
	for (int i = 2; i <= n; i++) {
		size_t temp = cur;
		cur += prev;
		prev = temp;
	}
	return cur;
}
