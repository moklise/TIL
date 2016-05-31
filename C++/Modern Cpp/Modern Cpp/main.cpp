//
//  main.cpp
//  Modern Cpp
//
//  Created by 민석 on 2016. 5. 30..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>

void print_number(int* myInt)
{
//    assert(myInt != nullptr);
    std::cout << *myInt << std::endl;
}

int main(int argc, const char * argv[]) {

    std::vector<std::string> v = { "감자", "고구마", "옥수수" };
    
    
    // Using Lambda
    std::for_each(v.begin(), v.end(), [](std::string s){
        if(s == "고구마"){
            std:: cout << s << std::endl;
        };
    });
    
    // Using For
    for(std::vector<std::string>::iterator iter = v.begin() ; iter != v.end() ; iter++){
        if(*iter == "고구마"){
            std::cout << *iter << std::endl;
        }
    }
    
    int a = 10;
    int *b = nullptr, *c = nullptr;
    
    b = &a;
    
    print_number(b);
    print_number(c);
    
    
    
    
    
    return 0;
}