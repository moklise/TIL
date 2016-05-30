//
//  auto.cpp
//  Modern Cpp
//
//  Created by 민석 on 2016. 5. 30..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(void){
    
    // Base auto Sample in for
    vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
    
    for( auto i : v ){
        cout << i << endl;
    }
    
}
