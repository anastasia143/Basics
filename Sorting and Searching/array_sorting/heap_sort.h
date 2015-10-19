#pragma once

/** Heap Sort
 *    best   |  average  |  worst
 * O(n*log n)  O(n*log n)  O(n*log n)
**/

void heap_sort(int size, int* arr);
void down_heap(int vertex, int size, int* arr);
