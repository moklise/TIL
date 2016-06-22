//
//  lambda.cpp
//  Modern Cpp
//
//  Created by 민석 on 2016. 5. 30..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    // Lambda : [Capture-list](parameter){code};
    
    // Base lambda Sample
    auto f = [](){};
    
    // Lambda in for
    // 두 가지 방식으로 나타낼수 있다.
    // 1. Capture List를 이용한 Lambda식
    // 2. Params를 이용한 람다식
    
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    // ###### 1 #####
    for( auto i : v ){
        auto f2 = [i](){
            cout << i << " ";
        };
        
        f2();
    }
    
    
    // ###### 2 #####
    auto f3 = [](int i){ cout << i << " ";};
    
    for(auto i : v)
        f3(i);
    
    // Lambda in for_each
    for_each(v.begin(), v.end(), [](int i){cout << i << " ";});
    
    
    // 람다 표현식을 이용하여 짝수를 2배수로 지정하기
    vector<int> v2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for_each(v2.begin(), v2.end(), [](int& _i){if(!(_i%2)) _i*=_i;});
    
    for(auto i : v2) cout << i << " ";

}


// 람다 표현식 되게 매력있는 부분인 것 같다.
// 이 람다표현식은 클로저 프로그래밍 기법의 한 부분이라고 한다.
// 람다 표현식을 사용함으로써 간결성 확보, 퍼포먼스 향상의 이점이 있다고 한다.