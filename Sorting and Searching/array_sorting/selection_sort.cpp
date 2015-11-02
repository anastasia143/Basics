#include "selection_sort.h"

void selection_sort(int size, int* arr)
{
	for (int i = 0; i < size; i++) {
		int min = i;
		for (int k = i; k < size; k++)
			if (arr[k] < arr[min])
				min = k;
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}
