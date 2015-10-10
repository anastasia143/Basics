#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <queue>
#include "stdio.h"

using namespace std;

/**
 * @brief The Graph class
 * A graph is an abstract data type that is meant to implement the undirected graph and 
 * directed graph concepts from mathematics.
 *
 * Representation:
I. Adjacency list
Vertices are stored as records or objects, and every vertex stores a list of adjacent vertices.
This data structure allows the storage of additional data on the vertices. Additional data can be
stored if edges are also stored as objects, in which case each vertex stores its incident edges and
each edge stores its incident vertices.

II. Adjacency matrix
A two-dimensional matrix, in which the rows represent source vertices and columns represent destination
vertices. Data on edges and vertices must be stored externally. Only the cost for one edge can be stored
between each pair of vertices.

III. Incidence matrix
A two-dimensional Boolean matrix, in which the rows represent the vertices and columns represent the edges.
The entries indicate whether the vertex at a row is incident to the edge at a column.

*              Adjacency list | Adjacency matrix | Incidence matrix
Store graph          O(|V|+|E|)           O(|V|^2)        O(|V|*|E|)
Add vertex                 O(1)           O(|V|^2)        O(|V|*|E|)
Add edge                   O(1)               O(1)        O(|V|*|E|)
Remove vertex            O(|E|)           O(|V|^2)        O(|V|*|E|)
Remove edge              O(|E|)               O(1)        O(|V|*|E|)
Query: are vertices      O(|V|)               O(1)            O(|E|)
x and y adjacent?
*/

class Graph
{
public:
	Graph();
	~Graph();

	void depthFirstSearch();
	void breadthFirstSearch();

private:
	void depthFirstSearchHelper(int vertex, bool* &label);
	void breadthFirstSearchHelper(queue<int>* &vertexQueue, bool* &label);

	int** arr;
	int vertexCount;
	int edgeCount;
};

