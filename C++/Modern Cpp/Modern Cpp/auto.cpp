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

template<class T>
class Matrix {
public:
    T i;
    Matrix& operator=(const Matrix& m){
        this->i = m.i;
        return *this;
    }
    
    Matrix operator+(const Matrix& m){
        Matrix* m0 = new Matrix();
        
        m0->i = this->i + m.i;
        
        return *m0;
    }
    
    
};

int main(void){
    
    // Base auto Sample in for
    vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
    
    for( auto i : v ){
        cout << i << endl;
    }
    
    // 형식 명시 초기치 관용구와 auto
    
    Matrix<int> m1, m2, m3, m4;
    
//    auto sum = static_cast<Matrix>(m1 + m2 + m3 + m4);
    
    
}
