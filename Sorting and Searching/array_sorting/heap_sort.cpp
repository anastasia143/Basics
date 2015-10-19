#include "heap_sort.h"

void heap_sort(int size, int* arr)
{
	// heap building
	for (int i = size / 2; i >= 0; i--)
		down_heap(i, size - 1, arr);

	for (int i = size - 1; i > 0; i--) {
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp; // change the first and the last
		down_heap(0, i - 1, arr); // restore heap
	}
}

void down_heap(int vertex, int size, int* arr)
{
	int vertex_value = arr[vertex];

	while (vertex <= size / 2) {    // vertex has childrens
		int child = 2 * vertex;
		if (child < size && arr[child] < arr[child + 1]) // greatest son
			child++;
		if (vertex_value >= arr[child])
			break;
		arr[vertex] = arr[child]; // up son
		vertex = child;
	}
	arr[vertex] = vertex_value; // down parent
}
