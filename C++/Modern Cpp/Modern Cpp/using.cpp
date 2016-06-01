//
//  using.cpp
//  Modern Cpp
//
//  Created by 민석 on 2016. 6. 1..
//  Copyright © 2016년 민석. All rights reserved.
//

// Effective Modern C++
// Section 9

#include <iostream>
using namespace std;


// alias 를 위해선 typedef 보다는 using이 더 좋다
template <class T>
using remove_const_t = typename remove_const<T>::type;

template <class T>
using remove_reference_t = typename remove_reference<T>::type;

template <class T>
using add_lvalue_reference_t = typename remove_reference<T>::type;

int main(void){
    
}


// 형식변환을 사용할때는
// remove_const_t::type 같이 뒤에 접미사 "::type"을 붙여줘야 할 경우가 존재한다.
// typedef를 사용하여 별칭을 지어준 경우에는 typedef 한 이름 앞에 typename을 반드시 붙여줘야하므로
// 번거로운 작업이 될 수 있다.



// #
// typedef는 템플릿화를 지원하지않지만, 별칭 선언은 지원한다.
// 별칭 템플릿에서는 "::type" 접미어를 붙일 필요가 없다. 템플릿 안에서 typedef를 지칭할 떄에는 "typename"을 지칭해야 할 경우가 많다.
// C++14는 C++11의 모든 형식특질변환에 대한 별칭 템플릿들을 제공한다.