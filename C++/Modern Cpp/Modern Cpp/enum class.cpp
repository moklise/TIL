//
//  enum class.cpp
//  Modern Cpp
//
//  Created by 민석 on 2016. 6. 1..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>
using namespace std;

enum Color { black, white, red };

enum class Color_c { black, white, red };

int main(void)
{

    //Color_c c = white; // Error! 이 범위에 white라는 이름의 열거자가 없음 (?)
    
    // namespace 를 이용하여 선언해주어야 함.
    Color_c c = Color_c::white;
    auto c_1 = Color_c::red;
    
}


// 범위 있는 enum ( enum class )를 사용하자