#pragma once
#include <iostream>

/** 9.1 You are given two sorted arrays, A and B, and A has a large enough
 * buffer at the end to hold B. Write a method to merge B into A in sorted order.
**/

using namespace std;

void sort(int* A, int* B, int n, int m);

void test()
{
	int* arr1 = new int[6];
	arr1[0] = 4;
	arr1[1] = 9;

	int* arr2 = new int[4];
	arr2[0] = 1;
	arr2[1] = 5;
	arr2[2] = 6;
	arr2[3] = 10;

	sortToA(arr1, arr2, 2, 4);

	for (int i = 0; i < 6; i++) {
		cout << arr1[i] << " ";
	}

	delete[] arr1;
	delete[] arr2;
}

void sortToA(int* A, int* B, int n, int m)
{
	int count = n + m - 1;
	int ac = n - 1;
	int bc = m - 1;

	while (ac >= 0 && bc >= 0) {
		if (A[ac] >= B[bc]) {
			A[count--] = A[ac--];
		}
		else {
			A[count--] = B[bc--];
		}
	}

	while (bc >= 0) {
		A[count--] = B[bc--];
	}
}
