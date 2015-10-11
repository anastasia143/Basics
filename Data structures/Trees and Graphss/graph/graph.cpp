#include "graph.h"

Graph::Graph()
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

}

Graph::~Graph()
{
	for (int i = 0; i < vertexCount; i++)
		delete[] arr[i];
	delete[] arr;
}

void Graph::depthFirstSearch()
{
	bool* label = new bool[vertexCount];
	for (int i = 0; i < vertexCount; i++)
		label[i] = false;
	depthFirstSearchHelper(1, label);
	delete[] label;
}

void Graph::depthFirstSearchHelper(int vertex, bool* &label)
{
	if (!label[vertex]) {
		label[vertex] = true;
		cout << vertex << " ";
		for (int i = 0; i < vertexCount; i++) {
			if (arr[vertex][i] == 1)
				depthFirstSearchHelper(i, label);
		}
	}
}

void Graph::breadthFirstSearch()
{
	queue<int>* vertexQueue = new queue<int>;
	vertexQueue->push(1);

	bool* label = new bool[vertexCount];
	for (int i = 0; i < vertexCount; i++)
		label[i] = false;

	breadthFirstSearchHelper(vertexQueue, label);
	delete vertexQueue;
	delete[] label;
}

void Graph::breadthFirstSearchHelper(queue<int>* &vertexQueue, bool* &label)
{
	while (!vertexQueue->empty()) {
		int vertex = vertexQueue->front();
		vertexQueue->pop();
		cout << vertex << " ";
		for (int i = 1; i < vertexCount; i++) {
			if ((arr[vertex][i] == 1) && !label[i]) {
				label[i] = true;
				vertexQueue->push(i);
			}
		}
	}
}

