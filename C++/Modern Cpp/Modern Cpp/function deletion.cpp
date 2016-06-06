//
//  function deletion.cpp
//  Modern Cpp
//
//  Created by 민석 on 2016. 6. 6..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>

typedef struct{
    bool isLucky(int _i);
    bool isLucky(char _c) = delete;
    bool isLucky(char* _c) = delete;
    bool isLucky(bool _b) = delete;
    bool isLucky(double _d) = delete;
}FORM;

bool FORM::isLucky(int _i){
    return true;
};

int main(void){
    FORM A;
    std::cout << A.isLucky(1) << std::endl;
//    std::cout << A.isLucky(1) << std::endl;
    
    auto isLucky2 = [](int _i){if(!(_i%2)) return true; return false;};
    
    std::cout << isLucky2(2) << std::endl;
    
    // DELETION 적용된 함수의 호출
    A.isLucky('A');     // Error!!
    A.isLucky("AAA");   // Error!!
    A.isLucky(1.1);     // Error!!
}
