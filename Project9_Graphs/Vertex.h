#pragma once
#include <string>
class Vertex
{
public:
	Vertex();
	Vertex(std::string a);
	~Vertex();
	std::string label;
	bool visited;
	int previousVertex;
	float distance;
};

