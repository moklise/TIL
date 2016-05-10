#include "Heuristic.h"
#include <algorithm>


Heuristic::Heuristic(Graph* graph, int source, int sink)
{
	this->graph = graph;
	foots.push_back(source);
	this->goal = sink;
}

Heues Heuristic::EnumNext() {
	Heues nheues;
	int last_foot = (*foots.rbegin());
	Neighbors neighbors = graph->FindNeighbors(last_foot);
	FIter seek = neighbors.begin();
	FIter last = neighbors.end();
	for (; seek != last; ++seek) {
		if (find(foots.begin(), foots.end(), *seek) == foots.end()) {
			nheues.push_back(new Heuristic(this, *(seek)));
		}
	}

	return nheues;
}

bool Heuristic::IsGoal()const {
	return (*foots.rbegin()) == goal;
}

void Heuristic::View()const {
	cout << " Foots: ";
	CFIter seek = foots.begin();
	CFIter last = foots.end();
	for (; seek != last; ++seek) {
		cout << (*seek) << " ";
	}
	cout << endl;
}

Heuristic::Heuristic(const Heuristic *bheu, int vt) {
	this->graph = bheu->graph;
	foots = bheu->foots;
	this->goal = bheu->goal;

	foots.push_back(vt);
}// ??
