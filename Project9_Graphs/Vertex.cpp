#include "stdafx.h"
#include <string>
#include "Vertex.h"
using namespace std;

Vertex::Vertex() {

}
Vertex::Vertex(string letter)
{
	label = letter;
	distance = INFINITY;
	visited = false;
	previousVertex = -1;
}


Vertex::~Vertex()
{
}
