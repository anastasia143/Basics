#pragma once
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/** 9.2 Write a method to sort an array of strings
 * so that all the anagrams are next to each other.
**/

bool anagramComparator(string &str1, string &str2)
{
	sort(str1.begin(), str2.end());
	sort(str2.begin(), str2.end());
	return str1.compare(str2);
}

void anagramSort(vector<string> &strVector) {
	sort(strVector.begin(), strVector.end(), anagramComparator);
}

