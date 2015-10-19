#include "merge_sort.h"

using namespace std;

void merge_sort(int size, int* arr)
{
	int* helper = new int[size];
	for(int i = 0; i < size; i++)
		helper[i] = 0;

	merge_sort(0, size - 1, arr, helper);
	delete[] helper;
}

void merge_sort(int left, int right, int* arr, int* helper)
{
	if (right <= left)
		return;
	int middle = (left + right) / 2;

	merge_sort(left, middle, arr, helper);
	merge_sort(middle + 1, right, arr, helper);

	int helper_size = right - left + 1;
	int left_counter = left;
	int right_counter = middle + 1;
	for (int i = 0; i < helper_size; i++) {
		if (((arr[left_counter] < arr[right_counter]) && (left_counter <= middle)) || (right_counter > right)) {
			helper[left + i] = arr[left_counter];
			left_counter++;
		}
		else {
			helper[left + i] = arr[right_counter];
			right_counter++;
		}
	}

	for (int i = left; i <= right; i++)
		arr[i] = helper[i];
}
