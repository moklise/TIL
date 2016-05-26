//
//  operatorPractice.cpp
//  playground
//
//  Created by 민석 on 2016. 5. 26..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>
using namespace std;

class man {
    char* name;
    int phoneNumber;
    static int numOfMan;
    
public:
    char* getName(){
        return name;
    }
    void setName(char* _name){
        delete[] name;
        name = new char[strlen(_name)];
        strcpy(name,_name);
    }
    
    int getNumber(){
        return phoneNumber;
    }
    void setNumber(int _num){
        phoneNumber = _num;
    }
    void showAboutHim(){
        cout << "#########" << endl;
        cout << getName() << endl;
        cout << getNumber() << endl;
    }
    
    man(){
        name = new char;
        strcpy(name, "");
        phoneNumber = 0;
        numOfMan++;
    }
    
    man(char* _name, int _number){
        name = new char[strlen(_name)];
        strcpy(name, _name);
        
        phoneNumber = _number;
    }
    
    man& operator=(man& A){
        delete[] name;
        name = new char[ strlen(A.getName())];
        strcpy(name, A.getName());
        
        phoneNumber = A.getNumber();
        
        return *this;
    }
    
};

int man::numOfMan = 0;

int main(void){
    
    man A;
    A.showAboutHim();
    man B("김갑수니",11);
    B.showAboutHim();
    A = B;
    A.showAboutHim();
    
    
    return 0;
}