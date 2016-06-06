//
//  move sementics.cpp
//  Modern Cpp
//
//  Created by 민석 on 2016. 6. 1..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>

class Person{
    std::string name;
    
public:
    auto getName(){
        return this->name;
    }
    
    Person(){
        name = "noname";
        std::cout << this->getName() << "says hi" << std::endl;
    }
    Person(std::string&& _name){
        name = std::move(_name);
        std::cout << this->getName() << "says hi" << std::endl;
    }
    Person(Person& newMan){
        name = std::move(newMan.name);
        std::cout << this->getName() << "says hi" << std::endl;
    }
    ~Person(){
        std::cout << this->getName() << "is gone" << std::endl;
    }
};

int main(void){
    Person A;
    Person B("GYU");
    Person C(B);
}