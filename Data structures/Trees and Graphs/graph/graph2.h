#pragma once
#define max 1000

class EdgeNode
{
public:
	int y;
	int weight;
	EdgeNode* next;
};

class Graph2
{
public:
	EdgeNode* edges[max]; // list of edges for each vertex
	int degree[max];
	int nVertices;
	int nEdges;
	bool directed;
};
