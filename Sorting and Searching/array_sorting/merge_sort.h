#pragma once
#include <iostream>
#include <cstdlib>

/** Merge Sort
 *    best   |  average  |  worst
 * O(n*log n)  O(n*log n)  O(n*log n)
**/

void merge_sort(int size, int* arr);
void merge_sort(int left, int right, int* arr, int* helper);
