#include <iostream>
#include <String>
#include <time.h>
#include <Windows.h>
#define N 10 // ��, ���� ũ��

struct NODE {
	int x;
	int y;
	int distance = 0;
	int status = 0;
	bool visited = true;
};
// x, y�� ��ǥ�� ����;
// 4*4ũ���� ���̸� 16���� NODE�� �����ؾ���
NODE screen[N][N];
int step = 0;
void showScreen();

// (0,1) �� ����
// (7,8) �� ��
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
	// �ؾ��ϴ� ��.
	// 1. ���� ¥�� Dijkstra �˰������� ��带 ����Ҽ� �ְԲ� ������ ��.
	// 2. �۵��� �Ǵ°��� Ȯ�εǸ�, minChoice �κ��� �ǵ�ų� �����Ͽ� ���� ���ϰ�.
	// 
	// # STEP �� �̵� ��. ���Ͻ��� �ƴ�
	// # 
	// # �ּ� �Ÿ��� ���� ���� ã����.
}

void showScreen()
{
	Sleep(1000);
	system("cls");
	for (auto i = 0; i < N + 2; i++)
		std::cout << "��";
	std::cout << std::endl;

	for (int i = 0; i < N; i++)
	{
		std::cout << "��";
		for (int j = 0; j < N; j++)
		{
			switch (screen[i][j].status)
			{
			case 1:
				std::cout << "��";
				break;
			case 2:
				std::cout << "��";
				break;
			default:
				std::cout << "��";
				break;
			}
		}
		std::cout << "��";
		std::cout << std::endl;
	}

	for (auto i = 0; i < N + 2; i++)
		std::cout << "��";
	std::cout << std::endl;
}

int main(void)
{
	//makeMap();
	initScreen();

	showScreen();
	//doFloyd();
}