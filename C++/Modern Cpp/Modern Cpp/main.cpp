//
//  main.cpp
//  Modern Cpp
//
//  Created by 민석 on 2016. 5. 30..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

template<class T>
void print_list(T value)
{
    std::cout << value << std::endl;
}

template<class First, class ...Rest>
void print_list(First first, Rest ...rest){
    std::cout << first << ", ";
    print_list(rest...);
}

template<class T>
struct S {
    std::vector<T> v;
    
    S(std::initializer_list<T> l): v(l){}
    void append(std::initializer_list<T> l){
        v.insert(v.end(), l.begin(), l.end());
    }
    auto begin(){
        return v.begin();
    }
    
    auto end(){
        return v.end();
    }
};

enum class Color { white, yellow, red, blue, green };

class Brush {
    Color c;
    int size;
    
    static std::string CheckColor(Color _c){
        switch (_c) {
            case Color::white:
                return "White";
                break;
                
            case Color::red:
                return "Red";
                
            default:
                return "Blue";
                break;
        }
    }
    
public:
    Brush(){
        c = Color::white;
        size = 1;
    }
    Brush(Color _c,int _size){
        size = _size;
        c = _c;
    }
    void show(){
        std::cout << CheckColor(this->c) << " " << size << std::endl;
    }
};

int main(int argc, const char * argv[]) {
    
    // Use map in C++ 14
    std::cout << "##### MAP TEST #####" << std::endl;
    std::map<int, std::string> mapping;
    
    mapping.insert({1,"hi"});
    
    
    std::cout << mapping[1] << std::endl;
    
    std::cout << "##### Enum Class #####" << std::endl;
    Brush A;
    A.show();
    
    Brush B(Color::blue, 3);
    B.show();
    
    
    print_list(42, "hello", 2.3, 'a');
    
    S<int> s = {1,2,3,4,5};
    s.append({1,2,3,4,5});
    
    for( auto i : s){
        std::cout << i << " ";
    }

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
    
    // 초기화가 Unified 되었다. -> initializer_list로!
    // {}를 시용한 생성자
    std::map<int, std::string> container{{1, "Open"}, {2, "Close"}};
    std::vector<int> container2 = {1,2,3,4,5,6,7,8,9};
    

    
    return 0;
}