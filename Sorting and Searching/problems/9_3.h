#pragma once

/** 9.3 Given a sorted array of n integers that has been rotated an unknown number of times,
 * give an O(log n) algorithm that finds an element in the array. You may assume that the array
 * was originally sorted in increasing order
 *
 * EXAMPLE:
 * Input: find 5 in array (15 16 19 20 25 1 3 4 5 7 10 14)
 * Output: 8 (the index of 5 in the array)
**/

int search(int* arr, int num, int left, int right)
{
	while (left <= right) {
		int mid = (left + right) / 2;

	if (arr[mid] == num)
		return mid;
	else if (arr[left] <= arr[mid]) {
		if (num > arr[mid])
			left = mid + 1;
		else if (num >= arr[left])
			right = mid - 1;
		else
			left = mid + 1;
	}
	else if (num < arr[mid])
		right = mid - 1;
	else if (num <= arr[right])
		left = mid + 1;
	else right = mid - 1;
	}
	return -1;
}

int search(int* arr, int num, int size) {
	return search(arr, 0, size - 1, num);
}
