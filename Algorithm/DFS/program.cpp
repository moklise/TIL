#include "Heuristic.h"
#include "Graph.h"
#include <stack>
#include <fstream>

using namespace std;

int main(void) {
	Graph * graph = new Graph(4000);

	ifstream inputFile("DB00139_AD.txt");
	int a, b;

	while (!inputFile.eof()) {
		inputFile >> a >> b;
		//graph->AddEdge(a, b);
		cout << a << " " << b << endl;;
	}


	//graph->AddEdge(3242, 423);
	graph->AddEdge(0, 2);
	graph->AddEdge(1, 2);
	graph->AddEdge(1, 3);
	graph->AddEdge(2, 4);
	graph->AddEdge(3, 6);
	graph->AddEdge(4, 5);
	graph->AddEdge(4, 6);
	graph->AddEdge(4, 7);
	graph->AddEdge(6, 8);

	graph->ViewNeighbors();

	stack<Heuristic *> hs;
	
	Heuristic * heu = new Heuristic(graph, 0, 8);
	hs.push(heu);

	while (!hs.empty()) {
		heu = hs.top();
		hs.pop();
		heu->View();

		Heues nheues = heu->EnumNext();
		HIter seek = nheues.begin();
		HIter last = nheues.end();
		for (; seek != last; ++seek) {
			if ((*seek)->IsGoal()) {
				cout << " ¼Ö·ç¼Ç : ";
				(*seek)->View();
				delete (*seek);
			}
			else
			{
				hs.push(*seek);
			}
		}
		delete heu;
	}

	system("pause");
	inputFile.close();
	return 0;
}
