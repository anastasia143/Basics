#pragma once

/** 1.1 Implement an algorithm to determine if a string has all unique characters.
 * What if you can not use additional data structures?
 *
 * Approach 1: Ascii array O(n)
 * Approach 2: Using a bit vector
 * Approach 3: Check every char with every other char O(n^2)
 * Approach 4: Sort the string O(n log n)
**/

// 1
bool isUniqueChars(char* str, int len)
{
	int size = 256;
	bool* label = new bool[256];

	for(int i = 0; i < size; i++)
			label[i] = false;

	for (int i = 0; i < size; i++) {
			int asciiCode = (int) str[i];

			if (label[asciiCode])
				return false;
			else
				label[asciiCode] = true;
	}
	return true;
}

// 2
bool isUniqueChars2(char* str, int len)
{
	int checker = 0;
	for (int i = 0; i < len; i++) {
		int asciiCode = (int) str[i];
		if ((checker & (1 << asciiCode)) > 0)
			return false;
		checker = checker | (1 << checker);
	}
	return true;
}
