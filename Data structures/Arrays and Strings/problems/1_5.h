#pragma once
#include <cstring>

/** 1.5 Write a method to replace all spaces in a string with %20.
**/

void replaceSpaces(char* str)
{
	int len = strlen(str);

	int spacesCount = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ')
			spacesCount++;
	}

	int len2 = len + 2 * spacesCount;
	str[len2] = '\0';
	int counter = len2 - 1;
	for (int i = len - 1; i >= 0; i--) {
		if (str[i] == ' ') {
			str[counter] = '0';
			str[counter - 1] = '2';
			str[counter - 2] = '%';
			counter -= 3;
		}
		else {
			str[counter] = str[i];
			counter--;
		}
	}
}
