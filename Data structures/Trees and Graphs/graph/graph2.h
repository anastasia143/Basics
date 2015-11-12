#pragma once
#define max 1000

class EdgeNode
{
public:
	EdgeNode(int y, int weight, EdgeNode* next)
		: y(y)
		, weight(weight)
		, next(next) {}
	int y;
	int weight;
	EdgeNode* next;
};

class Graph2
{
public:
	Graph2(bool directed)
		: directed(directed)
		, nVertices(0)
		, nEdges(0)
	{
		for (int i = 1; i <= max; i++)
			degree[i] = 0;
		for (int i = 1; i <= max; i++)
			edges[i] = NULL;
	}

	insertEdge(int x, int y, int weight, bool pair)
	{
		EdgeNode *p;
		p = new EdgeNode(y, weight, edges[x]);
		edges[x] = p;
		degree[x]++;
		if (pair)
			insertEdge(y,x, weight, false);
		else
			nEdges++;
	}

	EdgeNode* edges[max];
	int degree[max];
	int nVertices;
	int nEdges;
	bool directed;
};
