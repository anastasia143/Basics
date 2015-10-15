#pragma once
#include <cstring>

/** 1.2 Write code to reverse a C-Style String. (C-String means that "abcd"
 * is represented as five characters, including the null character.)
**/

void reverse(char* str)
{
	int size = strlen(str);
	int halfSize = size / 2;
	char temp = '0';

	for (int i = 0; i < halfSize; i++) {
		temp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = temp;
	}
}

void reverse2(char *str) {
	char* end = str;
	char tmp = '0';

	if (str) {
		while (*end) {
			++end;
		}
		--end;
		while (str < end) {
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}
}
