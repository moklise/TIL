#pragma once
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Neighbors;
class Graph
{
	const int vn;
	int **matrix;

public:
	Graph(int vn);
	~Graph();
	void AddEdge(int source, int sink);
	void ViewNeighbors()const;
	void ViewNeighbor(int vt)const;
	Neighbors FindNeighbors(int vt);
};

