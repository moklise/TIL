//
//  cinErrorTest.cpp
//  Lab
//
//  Created by 민석 on 2016. 5. 21..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>
using namespace std;

int main(void){
    int val;
    
    if(!(cin >> val)){
        cout << "Please Check Input Error" << endl;
        cin.clear();
        cin.ignore(numeric_limits<int>::max(),'\n');
        
        //
        // getline 과 cin 을 혼용해서 사용할때 쓰레기값을 입력받는 경우를 방지하기 위한 예외처리
        // cin.clear() : cin에 대한 Error State를 초기화함
        // cin.ignore(__SIZE, __DELIMETER__) : __SIZE__만큼 범위에서 __DELIMETER__ 를 무시함.
        //
    }
    
    cout << val;
}

// 의외로 많이 쓰이는 예외처리더라.
// 책에서 더 참고할 것.