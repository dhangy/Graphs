#pragma once
#include <string>
#include <queue>
#include "Vertex.h"
class Graph
{
public:
	Graph();
	~Graph();
	void AddEdge(std::string from, std::string to, int weight);
	void AddVertex(std::string label);
	bool isEdge(int sourceIndex, int targetIndex);
	int GetWeight(int sourceIndex, int targetIndex);
	void BreadthFirstSearch(std::string startingvertex);
	void DijkstraShortedPath(std::string startingVertex);
	void PrintGraph();
	int FindIndex(std::string a);
	void resetVertex();
	void printSolution(int startingIndex);
private:
	const static int MAX_VERTICES = 10;
	int matrix[MAX_VERTICES][MAX_VERTICES] = { { 0 } };
	Vertex vertices[MAX_VERTICES];
	int numVertices;

};

