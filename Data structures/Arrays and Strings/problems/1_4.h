#pragma once
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/** 1.4 Write a method to decide if two strings are anagrams or not.
 *
 * Approach 1:
 * Sort strings O(n * log n)
 *
 * Approach 2:
 * Count and compare numbers of each symbol in each str
**/

bool isAnagrams(string str1, string str2)
{
	int len = str1.length();
	int len2 = str2.length();
	if (len2 != len)
		return false;

	std::sort(str1.begin(), str1.end());
	std::sort(str2.begin(), str2.end());


	for (int i = 0; i < len; i++) {
		if (str1[i] != str2[i])
			return false;
	}
	return true;
}

bool isAnagrams2(string &str1, string &str2)
{
	int len = str1.length();
	int len2 = str2.length();

	if (len2 != len)
		return false;

	int charSize = 256;
	int counter[charSize];
	for (int i = 0; i < charSize; i++)
		counter[i] = 0;


	for (int i = 0; i < len; i++) {
		counter[(int) str1[i]]++;
	}
	for (int i = 0; i < len; i++) {
		int asciiCode = (int) str2[i];
		counter[asciiCode]--;
	}
	for (int i = 0; i < charSize; i++) {
		if (counter[i] != 0)
			return false;
	}
	return true;
}
