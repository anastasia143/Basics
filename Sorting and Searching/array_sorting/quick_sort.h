#pragma once
#include <iostream>

/** Quick Sort
 *    best   |  average  |  worst
 * O(n*log n)  O(n*log n)  O(n^2)
**/

void quick_sort(int size, int* arr);
void quick_sort(int left_border, int right_border, int* arr);
