#include "insert_sort.h"

void insert_sort(int size, int *arr)
{
	int temp = 0;
	int border = 0;
	for (int i = 1; i < size; i++) {
		temp = arr[i];
		border = i - 1;
		while (border >= 0 && arr[border] > temp) {
			arr[border + 1] = arr[border];
			arr[border] = temp;
			border--;
		}
	}
}
