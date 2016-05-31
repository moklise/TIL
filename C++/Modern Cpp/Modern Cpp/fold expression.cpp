//
//  fold expression.cpp
//  Modern Cpp
//
//  Created by 민석 on 2016. 5. 30..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>


template<typename T, typename... Ts>
void doSomeWork(Ts&&... params)
{
    std::cout << "딩" << std::endl;
}

int main(void)
{
    int a, b, c;
    a = 1;
    b = 2;
    c = 3;
}