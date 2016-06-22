// Smart pointer

#include <iostream>
#include <memory>

int main(void)
{
	std::unique_ptr<int> a;
	*a = 0;

	auto lamdbaDecltype = [](int* ptr) {
		std::cout << "done" << std::endl;
		delete ptr;
	};

	std::unique_ptr<int, decltype(lamdbaDecltype) > b;
	*b = 10;
}

// std::auto_ptr
// : C++98 �� ����� Ŭ����. ������ �ش� ���� ���ٰ� �մϴ�.
// std::unique_ptr
// : C++11�� ������ ǥ��ȭ �õ�
// : ������ �������̱⶧���� ������ �õ��� ��� ���簡 �ƴ� �̵��� �߻��Ѵ�.
//
// std::shared_ptr
//  : ������ ������
//	: ������ �������̱⋚���� ������ �õ��� ��� ���簡 �ȴ�.
//
// std::weak_ptr

// �� �ڼ��� �˾� ����.