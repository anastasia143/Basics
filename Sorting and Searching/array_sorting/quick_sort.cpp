#include "quick_sort.h"

void quick_sort(int size, int* arr)
{
	quick_sort(0, size - 1, arr);
}

void quick_sort(int left_border, int right_border, int* arr)
{
	int first = left_border;
	int last = right_border;
	int middle = arr[(left_border + right_border) / 2];

	while (first <= last) {
		while (arr[first] < middle)
			first++;

		while (arr[last] > middle)
			last--;

		if (first <= last) {
			std::swap(arr[first], arr[last]);
			first++;
			last--;
		}

	}

	if (first < right_border)
		quick_sort(first, right_border, arr);
	if (left_border < last)
		quick_sort(left_border, last, arr);
}
