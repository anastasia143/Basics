#pragma once
#include <string>
#include <vector>

/** 8.4 Write a method to compute all permutations of a string
 * ========================================================================
 * For example, if our string is “abc”, we would do the following:
1. Let first = “a” and let remainder = “bc”
2. Let list = permute(bc) = {“bc”, “cd”}
3. Push “a” into each location of “bc” (--> “abc”, “bac”, “bca”) and “cb” (--> “acb”, “cab”, “cba”)
4. Return our new list

This solution takes O(n!) time, since there are n! permutations.
**/

using namespace std;

string insertCharAt(string word, char c, int i) {
	if (word.size() == 1) {
		if (i == 0)
			return c + word;
		else
			return word + c;
	}

	string wordClone(word);
	string part1 = word.substr(0, i);
	string part2 = wordClone.substr(i, wordClone.size());
	return part1 + c + part2;
}

vector<string> getPerms(string const &str)
{
	int size = str.size();

	vector<string> res;

	if (size == 1) {
		res.push_back(str);
		return res;
	};
	if (size == 2) {
		res.push_back(str);
		string str2;
		str2.push_back(str.at(1));
		str2.push_back(str.at(0));
		res.push_back(str2);
		return res;
	}

	string newStr = str.substr(0, size - 1);
	vector<string> newStrPerms = getPerms(newStr);

	char c = str.at(size - 1);
	for (string newStrPerm : newStrPerms) {
		for (int i = 0; i < size; i++) {
			string stringWithNewChar = insertCharAt(newStrPerm, c, i);
			res.push_back(stringWithNewChar);
		}
	}
	return res;
}
