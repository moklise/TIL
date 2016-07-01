// 
// 160701 �ڹμ�
// Codeground 2015 SCPC 2015
// 
// ���� �� ���ϱ�
//
//b > N �ϰ�� ���ڸ����� ������ �͵� ���ϼ��� ����
//b < N �ϰ�� �״��
//
//	N�� b�� ���ؼ� ���ϼ��� �Ǵ� �ּ��� ���� ���� b
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