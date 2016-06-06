//
//  variadic template.cpp
//  Modern Cpp
//
//  Created by 민석 on 2016. 6. 1..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>

template <class T>
void print_list(T v){
    std::cout << v << " ";
}

template <class T, class ...Rest>
void print_list(T v, Rest ...rest){
    std::cout << v << " ";
    print_list(rest...);
}

int main(void){
    print_list("asdf", 's',1,4,"2.3");
}

// !!!!!variadic template은 재귀 함수를 끝내기 위한 별도의 함수가 필요하다.
// !!!!이 경우에선 위쪽 print_list가 그런 역할을 하고있다.

// 처리 순서
// print_list(first = "asdf", ...rest = 's', 1,4,"2.3");
//  asdf
// print_list(first = 's', ...rest = 1,4, "2.3");
//  s
// print_list(first = 1, ...rest = 4, "2.3");
//  1
// ...
// ...
// ...