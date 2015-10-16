#pragma once

/** 1.3 Design an algorithm and write code to remove the duplicate characters in a string
 * without using any additional buffer. NOTE: One or two additional variables are fine.
 * An extra copy of the array is not.
 *
 * FOLLOW UP
 * Write the test cases for this method.
 *
 * Approach 1: No (Large) Additional Memory:
 * For each character, check if it is a duplicate of already found characters. O(n^2)
 *
 * Approach 2: With Additional Memory of Constant Size
 * Ascii buffer O(n)
 *
 * Test Cases:
1. String does not contain any duplicates, e.g.: abcd
2. String contains all duplicates, e.g.: aaaa
3. Null string
4. String with all continuous duplicates, e.g.: aaabbb
5. Empty string
6. String with non-contiguous duplicates, e.g.: abababa
**/

void removeDuplicates(char* str)
{
	int len = strlen(str);
	int counter = 1;
	for (int i = 1; i < len; i++) {
		bool hasDuplicate = false;
		for(int k = 0; k <i; k++) {
			if (str[i] == str[k]) {
				hasDuplicate = true;
				break;
			}
		}
		if (!hasDuplicate) {
			str[counter] = str[i];
			counter++;
		}
	}
	str[counter] = '\0';
}

void removeDuplicates2(char* str)
{
	int charSize = 256;
	bool label[charSize];

	for (int i = 0; i < charSize; i++)
		label[i] = false;

	int len = strlen(str);
	int counter = 1;
	for (int i = 1; i < len; i++) {
		if (!label[str[i]]) {
			label[(int) str[i]] = true;
			str[counter] = str[i];
			counter++;
		}
	}
	str[counter] = '\0';

}
