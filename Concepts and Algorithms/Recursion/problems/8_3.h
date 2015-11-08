#pragma once
#include <vector>
#include <math.h>

/** 8.3 Write a method that returns all subsets of a set.
 * =========================================================
 * 2^n subsets
**/

using namespace std;

vector<vector<int> > findMultiset(vector<int> set)
{
	vector<vector<int> > result;
	int resSize = pow(2, set.size());
	int setSize = set.size();
	for (int i = 0; i < resSize; i++) {
		vector<int> subset;
		int ii = i;
		for (int k = 0; k < setSize; k++) {
			if (ii & 1 > 0)
				subset.push_back(set.at(k));
			ii >>= 1;
		}
		result.push_back(subset);
	}
	return result;
}




