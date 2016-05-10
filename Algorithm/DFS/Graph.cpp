#include "Graph.h"
#include <string>

Graph::Graph(int vn)
	:vn(vn)
{
	matrix = new int*[vn];
	for (int i = 0; i < vn; i++) {
		matrix[i] = new int[vn];
		memset(matrix[i], 0, sizeof(int)*vn);
	}
}


Graph::~Graph()
{
	for (int i = 0; i < vn; i++) {
		delete[] matrix[i];
	}

	delete[] matrix;
}

void Graph::AddEdge(int source, int sink) {
	matrix[source][sink] = 1;
	matrix[sink][source] = 1;
}

void Graph::ViewNeighbors()const {
	cout << "ÀÌ¿ôÁ¤Á¡ : " << endl;
	for (int i = 0; i < vn; i++) {
		cout << i << " ÀÇ ÀÌ¿ô : ";
		ViewNeighbor(i);
	}
	cout << endl;
}

void Graph::ViewNeighbor(int vt)const {
	for (int i = 0; i < vn; i++)
	{
		if (matrix[vt][i])
		{
			cout << i << " ";
		}
	}
	cout << endl;
}

Neighbors Graph::FindNeighbors(int vt) {
	Neighbors neighbors;
	for (int i = 0; i < vn; i++)
	{
		if (matrix[vt][i])
		{
			neighbors.push_back(i);
		}
	}
	return neighbors;
}