//
//  attribute.cpp
//  Modern Cpp
//
//  Created by 민석 on 2016. 5. 30..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>

[[noreturn]] void func1(){
    std::cout << "NORETURN" << std::endl;
}


int main(void) {
    
    int selector = 1;
    
    // C++ 17 : maybe_unused, fallthrought
    [[maybe_unused]] int unused_variation = 0;
    
    switch (selector) {
        case 0:
        case 1:
            std::cout << "뀨뀨꺄꺄" << std::endl;
            [[fallthrought]];
            
        case 2:
            std::cout << "뀨" << std::endl;
        default:
            break;
    }
}


// http://en.cppreference.com/w/cpp/language/attributes