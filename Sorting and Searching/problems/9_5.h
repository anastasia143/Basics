#pragma once
#include <iostream>

using namespace std;

/** 9.5 Given a sorted array of strings which is interspersed with empty strings,
 * write a method to find the location of a given string.
 *
 * Example: find "ball" in ["at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""] will return 4
 * Example: find "ballcar" in ["at", "", "", "", "", "ball", "car", "", "", "dad", "", ""] will return -1
**/

int find(string str, string* arr, int size)
{
	if (str.compare("") == 0) {
		for (int i = 0; i < size; i++)
			if (arr[i].empty())
				return i;
		return -1;
	}

	int left = 0;
	int right = size - 1;
	while (left <= right) {
		while (left <= right && arr[right].empty())
			right--;

		if (right < left)
			return -1;

		int mid = (left + right) >> 1; // : 2
		while (arr[mid].empty())
			mid++; // will always find one

		int comp = str.compare(arr[mid]);

		if (comp == 0) {
			return mid;
		}

		if (comp < 0)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

void test4()
{
	string str;
	str = "ball";
	string arr[13] {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
	cout << find(str, arr, 13) << endl;

	string str2;
	str2 = "ballcar";
	string arr2[12] {"at", "","","","", "ball", "car", "","", "dad","",""};
	cout << find(str2, arr2, 12) << endl;
}



