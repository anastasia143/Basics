#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <queue>
#include "stdio.h"

using namespace std;

/** 4.2 Given a directed graph, design an algorithm to find out
 * whether there is a route between two nodes.
**/

class Graph
{
public:
	Graph()
		: vertexCount(13) // 12 + 1
		, edgeCount(11)
	{
		arr = new int*[vertexCount]; // Adjacency matrix
		for (int i = 0; i < vertexCount; i++)
			arr[i] = new int [vertexCount];

		for (int i = 0; i < vertexCount; i++)
			for (int k = 0; k < vertexCount; k++)
				arr[i][k] = 0;

		arr[1][7] = 1;
		arr[1][2] = 1;
		arr[2][6] = 1;
		arr[2][3] = 1;
		arr[3][5] = 1;
		arr[3][4] = 1;
		arr[1][8] = 1;
		arr[8][9] = 1;
		arr[8][12] = 1;
		arr[9][11] = 1;
		arr[9][10] = 1;

		cout << depthFirstSearchCheck(1, 6);
		cout << depthFirstSearchCheck(8, 6);
	}

	~Graph()
	{
		for (int i = 0; i < vertexCount; i++)
			delete[] arr[i];
		delete[] arr;
	}

	bool depthFirstSearchCheck(int start, int end)
	{
		bool* label = new bool[vertexCount];
		for (int i = 0; i < vertexCount; i++)
			label[i] = false;
		return depthFirstSearchCheckHelper(start, end, label);
		delete[] label;
	}

private:
	bool depthFirstSearchCheckHelper(int vertex, int end, bool* &label)
	{
		if (!label[vertex]) {
			label[vertex] = true;
			if (vertex == end)
				return true;
			bool success = false;
			for (int i = 0; i < vertexCount; i++) {
				if (arr[vertex][i] == 1)
					if (depthFirstSearchCheckHelper(i, end, label))
						success = true;
			}
			return success;
		}
		return false;
	}

	int** arr;
	int vertexCount;
	int edgeCount;
};
