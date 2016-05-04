//
//  main.cpp
//  playground
//
//  Created by 민석 on 2016. 5. 4..
//  Copyright © 2016년 민석. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;
const int Max = 50;

class PIC
{
public:
    int year;
    char* title;
    char* director;
    void Print();
    PIC();
    PIC(int Cyear, char Ctitle[Max], char Cdirector[Max]);
    PIC(const PIC &pt);
    ~PIC();
    
};
PIC::PIC()
{
    cout << "인자없는 생성자 호출!" << endl;
    year = 1953;
    title = new char[Max];
    director = new char[Max];
    strcpy(title, "From Here To Eternity");
    strcpy(director, "Fred Zinnemann");
}
PIC::PIC(int Cyear, char Ctitle[Max], char Cdirector[Max])
{
    title = new char[strlen(Ctitle) + 1];
    director = new char[strlen(Cdirector) + 1];
    cout << "인자있는 생성자 호출!" << endl;
    year = Cyear;
    strcpy(title, Ctitle);
    strcpy(director, Cdirector);
}
PIC::PIC(const PIC &pt)
{
    title = new char[strlen(pt.title)];
    director = new char[strlen(pt.director)];
    cout << "복사 생성자 호출!" << endl;
    year = pt.year;
    strcpy(title, pt.title);
    strcpy(director, pt.director);
}
PIC::~PIC()
{
    cout << "소멸자 호출!" << endl;
    if (title != NULL)
    {
        delete[]title;
        title = NULL;
    }
    if (director != NULL)
    {
        delete[]director;
        director = NULL;
    }
    
}
void PIC::Print()
{
    cout << year << endl << title << endl << director << endl;
}
int main()
{
    int i;
    char p[Max];
    char pi[Max];
    PIC mocie1;
    cout << "연도 : ";
    cin >> i;
    cout << "영화 : ";
    cin >> p;
    cout << "감독 : ";
    cin >> pi;
    PIC movie2(i, p, pi);
    PIC movie3(movie2);
    mocie1.Print();
    movie2.Print();
    movie3.Print();
}