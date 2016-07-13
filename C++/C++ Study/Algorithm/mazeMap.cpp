#include <iostream>
#include <String>
#include <time.h>
#include <Windows.h>
#define N 10 // 행, 열의 크기

struct NODE {
	int x;
	int y;
	int distance = 0;
	int status = 0;
	bool visited = true;
};
// x, y는 좌표를 뜻함;
// 4*4크기의 맵이면 16개의 NODE가 존재해야함
NODE screen[N][N];
int step = 0;
void showScreen();

// (0,1) 이 시작
// (7,8) 이 끝
int map[N][N] = {
	{0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 1, 1, 0, 1, 1, 1, 0 },
	{ 0, 1, 0 ,0, 0, 1, 0, 1, 0 },
	{ 0, 1, 0, 1, 1, 1, 0, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 0, 0 },
	{ 0, 1, 1, 1, 0, 1, 0, 1, 0 },
	{ 0, 1, 0, 0, 0, 1, 0, 1, 0 },
	{ 0, 1, 1, 1, 0, 1, 1, 1, 0 },
	{ 0, 0, 0, 0 ,0, 0, 0, 1, 0 }
};

const NODE& minChoice(const NODE& target)
{
	for (int i = target.x - 1; i < target.x + 2; i++)
	{
		for (int j = target.y - 1; i < target.y + 2; j++)
		{
			if (map[i][j] == 1 && screen[i][j].visited == false)
			{
				return screen[i][j];
			}
		}
	}
}

void makeMap()
{
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			map[i][j] = rand() % 2;
		}
	}
}

void initScreen()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			screen[i][j].status = map[i][j];
		}
	}
}

void setScreen(int _s, int _t)
{
	screen[_s][_t].status = 2;
}

void algorithm()
{
	// 해야하는 것.
	// 1. 각자 짜온 Dijkstra 알고리즘으로 노드를 사용할수 있게끔 포팅할 것.
	// 2. 작동이 되는것이 확인되면, minChoice 부분을 건들거나 응용하여 수를 줄일것.
	// 
	// # STEP 은 이동 수. 디스턴스가 아님
	// # 
	// # 최소 거리를 가장 빨리 찾을것.
}

void showScreen()
{
	Sleep(1000);
	system("cls");
	for (auto i = 0; i < N + 2; i++)
		std::cout << "■";
	std::cout << std::endl;

	for (int i = 0; i < N; i++)
	{
		std::cout << "■";
		for (int j = 0; j < N; j++)
		{
			switch (screen[i][j].status)
			{
			case 1:
				std::cout << "　";
				break;
			case 2:
				std::cout << "○";
				break;
			default:
				std::cout << "■";
				break;
			}
		}
		std::cout << "■";
		std::cout << std::endl;
	}

	for (auto i = 0; i < N + 2; i++)
		std::cout << "■";
	std::cout << std::endl;
}

int main(void)
{
	//makeMap();
	initScreen();

	showScreen();
	//doFloyd();
}