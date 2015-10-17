#pragma once
#include <string>

using namespace std;

/** 1.8 Assume you have a method isSubstring which checks if one word is a substring of another.
 * Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call
 * to isSubstring (i.e., “waterbottle” is a rotation of “erbottlewat”).
**/

bool isSubstring(string &s1, string &s2)
{
	return true;
}

bool isRotation(string &s1, string &s2)
{
	int len = s1.length();
	int len2 = s2.length();
	if (len != len2)
		return false;
	string s1s1 = s1 + s1;
	return isSubstring(s1s1, s2);
}
