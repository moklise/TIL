//
//  initializer_list.cpp
//  Modern Cpp
//
//  Created by 민석 on 2016. 6. 1..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>
#include <vector>


// 모든 데이터 컨테이너의 추가방법을 동일화함
// initializer_list 로!
template<class T>
struct S{
    std::vector<T> v;
    
    S(std::initializer_list<T> l)
    :v(l){ };
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

int main(void){
    
    S<char> s = {'a', 'b', 'c'};
    s.append({'d', 'e', 'f'});
    
    for(auto i : s){
        std::cout << i << " ";
    }
}
