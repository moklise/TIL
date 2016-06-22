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
// : C++98 의 비권장 클래스. 완전히 잊는 것이 좋다고 합니다.
// std::unique_ptr
// : C++11의 포인터 표준화 시도
// : 독점적 소유권이기때문에 대입을 시도할 경우 복사가 아닌 이동이 발생한다.
//
// std::shared_ptr
//  : 공동적 소유권
//	: 공동적 소유권이기떄문에 대입을 시도할 경우 복사가 된다.
//
// std::weak_ptr

// 더 자세히 알아 볼것.