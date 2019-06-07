#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
	Graph g;

	g.AddVertex("A");
	g.AddVertex("B");
	g.AddVertex("C");
	g.AddVertex("D");
	g.AddVertex("E");
	g.AddVertex("F");

	g.AddEdge("A", "B", 2);
	g.AddEdge("A", "F", 9);

	g.AddEdge("B", "F", 6);
	g.AddEdge("B", "D", 15);
	g.AddEdge("B", "C", 8);

	g.AddEdge("C", "D", 1);

	g.AddEdge("E", "C", 7);
	g.AddEdge("E", "D", 3);

	g.AddEdge("F", "E", 3);

	g.PrintGraph();

	g.BreadthFirstSearch("A");

	g.DijkstraShortedPath("A");
	g.DijkstraShortedPath("B");
	g.DijkstraShortedPath("C");
	g.DijkstraShortedPath("D");
	g.DijkstraShortedPath("E");
	g.DijkstraShortedPath("F");


	cout << "Press [Enter] to exit  ";
	getchar();
}