// 
// 160701 박민석
// Codeground 2015 SCPC 2015
// 
// 균일 수 구하기
//
//b > N 일경우 한자리수가 나오는 것도 균일수로 포함
//b < N 일경우 그대로
//
//	N이 b에 대해서 균일수가 되는 최소의 양의 정수 b
//
//	(b > 2)
// 
#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
	int testCase = 0;
	std::cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		int b = 2;
		int N;
		int min = 0;
		std::cin >> N;

		for (b; b < N; b++)
		{
			int N_copy = N;
			std::vector<int> list;

			while (N_copy > b)
			{
				list.push_back(N_copy%b);
				N_copy = N_copy / b;
			}
			if (N_copy == b)
				continue;

			list.push_back(N_copy);

			int basis = list[0];
			bool flag = true;
			for (auto iter = list.begin(); iter != list.end(); iter++)
				if (*iter != basis)	flag = false;

			if (flag) {
				min = b;
				break;
			}
		}
		if (b == N) min = b + 1;
		
		std::cout << "Case #" << i+1 << std::endl;
		std::cout << min << std::endl;
	}
}

// N : 36