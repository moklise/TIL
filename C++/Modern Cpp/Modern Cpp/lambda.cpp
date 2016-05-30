//
//  lambda.cpp
//  Modern Cpp
//
//  Created by 민석 on 2016. 5. 30..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(void){
    
    // Base lambda Sample
    auto f = [](){};
    
    // [Capture-list](parameter){code};
    
    // Lambda in for
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for( auto i : v ){
        auto f2 = [i](){
            cout << i << endl;
        };
        
        f2();
    }
    
    // Lambda in for_each
    for_each(v.begin(), v.end(), [](int i){cout << i << endl;});
}

