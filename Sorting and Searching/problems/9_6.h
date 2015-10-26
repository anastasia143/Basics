#pragma once
#include <iostream>
using namespace std;

/** 9.6 Given a matrix in which each row and each column is sorted,
 * write a method to find an element in it.
**/

bool findElement(int** arr, int num, int row_count, int column_count)
{
	int n = row_count - 1;
	int m = 0;

	while (n >= 0 && m < column_count) {
		if (num == arr[n][m]) {
			return true;
		}
		if (num > arr[n][m])
			m++;
		else
			n--;
	}
	return false;
}

void test2()
{
	int size = 4;
	int** arr = new int*[size];
	for (int i = 0; i < size; i++) {
		arr[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = i + j;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << findElement(arr, 100, size, size) << endl;
	cout << findElement(arr, 5, size, size) << endl;

	for (int i = 0; i < size; i++) {
		delete[] arr[i];
	}

	delete[] arr;
}
