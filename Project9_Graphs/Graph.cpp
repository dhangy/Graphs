#include "stdafx.h"
#include "Graph.h"
#include <iostream>
#include <set>
using namespace std;
Graph::Graph()
{
	numVertices = 0;
}

Graph::~Graph()
{
}

void Graph::AddEdge(string from, string to, int weight) {
	//need to take the string and pass into the vertices to get the number form
	int fromIndex = FindIndex(from);
	int toIndex = FindIndex(to);
	matrix[fromIndex][toIndex] = weight;
}

void Graph::AddVertex(std::string label) {
	vertices[numVertices] = Vertex(label);
	numVertices++;
}

bool Graph::isEdge(int fromIndex, int toIndex) {
	int temp = matrix[fromIndex][toIndex];
	if (matrix[fromIndex][toIndex] != 0) {
		return true;
	}
	else return false;
}

int Graph::GetWeight(int fromIndex, int toIndex) {
	if (isEdge(fromIndex, toIndex)) {
		return matrix[fromIndex][toIndex];
	}
}

void Graph::BreadthFirstSearch(std::string startingvertex) {
	int startingIndex = FindIndex(startingvertex);
	queue<int> que;
	que.push(startingIndex);
	vertices[startingIndex].visited = true;
	cout << "Breadth First Traversal starting at " << startingvertex << endl;
	while (!que.empty()) {
		int currentVertex = que.front();
		cout << "visited " << vertices[currentVertex].label << endl;
		que.pop();
		for (int i = 0; i < numVertices; i++) {
			if (matrix[currentVertex][i] != NULL && vertices[i].visited == false) {
				que.push(i);
			vertices[i].visited = true;
			}
		}
	}
	resetVertex();
}

void Graph::DijkstraShortedPath(std::string startingVertex) {
	resetVertex();
	cout << "\nShortest Distance starting from vertex " << startingVertex << endl;
	int startingIndex = FindIndex(startingVertex);
	vertices[startingIndex].distance = 0;
	queue<int> priorityQueue;
	priorityQueue.push(startingIndex);
	while (!priorityQueue.empty()) {
		int currentVertex = priorityQueue.front();
		priorityQueue.pop();
		vertices[currentVertex].visited = true;
		//Visisted all of the starting vertex's adj
		for (int i = 0; i < MAX_VERTICES; i++) {
			//need to find a way to see if things are adjacent
			if (matrix[currentVertex][i] != -1 ) {
				int adjacentVertex = i;
				int edgeWeight = GetWeight(currentVertex, adjacentVertex);
				float alternatePathDistance = vertices[currentVertex].distance + edgeWeight;
				if (alternatePathDistance < vertices[adjacentVertex].distance) {
					//if it is shorter update the distance
					vertices[adjacentVertex].distance = alternatePathDistance;
					vertices[adjacentVertex].previousVertex = currentVertex;
					priorityQueue.push(adjacentVertex);	
				}
			}
		}
	}
	printSolution(startingIndex);
}
	

int Graph::FindIndex(string label) {
	for (int i = 0; i < numVertices; i++) {
		 string temp = vertices[i].label;
		if (temp == label) {
			return i;
		}
	}
	return -1;
}
void Graph::resetVertex() {
	for (int i = 0; i < numVertices; i++) {
		vertices[i].visited = false;
		vertices[i].distance = INFINITY;
		vertices[i].previousVertex = -1;
	}
}

void Graph::printSolution(int startingIndex) {
	for (int i = 0; i < numVertices; i++) {
		string path;
		bool notDone = true;
		int tempPrevious = i;
		while (notDone) {
			//got ride of startingIndexx and made it -1;
			if (vertices[tempPrevious].previousVertex == -1) {
				string label = vertices[tempPrevious].label;
				path.append(label);
				notDone = false;
			}
			else {
				path.append(vertices[tempPrevious].label);
				path.append(",");
				tempPrevious = vertices[tempPrevious].previousVertex;
			}
		}
		string letter = vertices[i].label;
		if (vertices[i].distance > 1000000) {
			cout << "to: " << letter << "\t" << "no path" << endl;
		}
		else {
			int distance = vertices[i].distance;
			cout << "to: " << letter << "\t" << distance << "\t" << "Path: \t" << path << endl;
		}
	}
}

void Graph::PrintGraph() {
	cout << "\t";
	for (int i = 0; i < numVertices; i++)
	{
		cout << vertices[i].label << "\t";
	}
	cout << endl;
	for (int from = 0; from < numVertices; from++)
	{
		cout << vertices[from].label;
		for (int to = 0; to < numVertices; to++)
		{
			
			if (matrix[from][to] >= 1) {
				cout << "\t";
				cout << matrix[from][to];
			}
			else
				cout << "\t ";
		}
		cout << endl;
	}

	cout << endl;
}