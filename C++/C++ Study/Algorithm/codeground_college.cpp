#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

typedef struct edge{
	int s;
	int t;
	int w;

	edge(int _s, int _t, int _w)
		:s(_s),t(_t),w(_w)
	{}
}EDGE;

int numOfNode = 0;
int numOfEdge = 0;

void input(std::vector<EDGE>& network)
{
	int s, t, w;

	std::cin >> numOfNode >> numOfEdge;

	for (int i = 0; i < numOfEdge; i++)
	{
		std::cin >> s >> t >> w;

		network.push_back(EDGE(s, t, w));
	}

	for (auto iter = network.begin(); iter != network.end(); iter++)
	{
		std::cout << iter->s << " - " << iter->t << " " << iter->w << std::endl;
	}
}

std::vector<int> process(std::vector<EDGE> network)
{
	std::vector<int> noPay;
	std::vector<int> association = {0};
	queue<bool> waitSequence = false;;

	// BFS
	for (int i = 0; i < numOfNode; i++)
	{ 
		

		for_each(network.begin(), network.end(), [=](Relation rel)
		{
			if (rel.s == i)
			{
				waitSequence[rel.s] = true;
			}
		}
	}




}

int main(void)
{
	std::vector<Relation> network;
	input(network);
	process(network);
}



