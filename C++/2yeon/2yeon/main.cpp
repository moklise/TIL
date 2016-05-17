//
//  main.cpp
//  2yeon
//
//  Created by 민석 on 2016. 5. 17..
//  Copyright © 2016년 민석. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;
const int NAME_LEN = 20;
class Account
{
private:
    int id;
    int balance;
    char* name;
public:
    Account();
    Account(int id, int balance, char* name);
    Account(const Account& a);
    ~Account();
    Account&  operator=(const Account & a);
    void ShowAllData() const; // ¿¸√º µ•¿Ã≈Õ ∫∏ø©¡÷±‚
    int InMoney(int val); // æÛ∏∂ ¿‘±›
    bool OutMoney(int val); // æÛ∏∂ √‚±›
    int GetId()const;
    int GetBalance() const;
    char* GetName() const;
    void SetId(int val);
    void SetBalance(int val);
    void SetName(char* name);
};


Account::Account()
{
    cout << "¿Œ¿⁄ æ¯¥¬ ª˝º∫¿⁄" << endl;
    id = 0;
    balance = 0;
    name = new char[NAME_LEN];
}
Account::Account(int id, int balance, char* name)
{
    cout << "¿Œ¿⁄ ¿÷¥¬ ª˝º∫¿⁄" << endl;
    this->id = id;
    this->balance = balance;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
Account::Account(const Account& a)
{
    cout << "∫πªÁ ª˝º∫¿⁄" << endl;
    id = a.id;
    balance = a.balance;
    name = new char[strlen(a.name) + 1];
    strcpy(name, a.name);
}
int Account::GetId() const
{
    return id;
}
int Account::GetBalance() const
{
    return balance;
}
char* Account::GetName() const
{
    return name;
}
void Account::SetId(int val)
{
    id = val;
}
void Account::SetBalance(int val)
{
    balance = val;
}
void Account::SetName(char* name)
{
    if (this->name) {
        delete[] this->name; //ø¯∑°¿« ¿Ã∏ß «ÿ¡ˆ
    }
    this->name = new char[strlen(name) + 1]; //πŸ≤Ÿ∞Ì¿⁄«œ¥¬ ¿Ã∏ß ±Ê¿Ã »Æ∫∏«— »ƒ
    strcpy(this->name, name); //∫πªÁ
}
void Account::ShowAllData() const
{
    cout << "∞Ë¡¬ID: " << id;
    cout << "  ¿‹æ◊: " << balance;
    cout << "  ¿Ã∏ß: " << name << endl;
}
int Account::InMoney(int val)
{
    balance += val;
    return balance;
}
bool Account::OutMoney(int val)
{
    if (balance >= val) {
        balance -= val;
        return true;
    }
    else {
        return false;
    }
}
Account::~Account()
{
    cout << "º“∏Í¿⁄" << endl;
    delete[] name;
}
Account&  Account::operator=(const Account & a)
{
    if (this != &a)
    {
        delete[] name;
        name = new char[strlen(a.name) + 1];
        strcpy(name, a.name);
        id = a.id;
        balance = a.balance;
    }
    return *this;
}

const int ACT_MAX = 10;

enum { MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

void PrintMenu();
void Deposit(Account** C, int index);
void MakeAccount(Account** C, int& index);
void Withdraw(Account** C, int index);
void Inquire(Account** C, int index);
void Cleanup(Account** C, int index); //∏ﬁ∏∏Æ «ÿ¡ˆ

int main()
{
    Account* C[ACT_MAX]; //¡§¿˚∞¥√º∆˜¿Œ≈Õ
    int index = 0; //Ω«¡˙ number of Accounts
    
    int choice;
    while (true) {
        PrintMenu();
        cout << endl;
        cout << "º±≈√: ";
        cin >> choice;
        switch (choice) {
            case MAKE: //∞Ë¡¬ª˝º∫
                MakeAccount(C, index);
                break;
            case DEPOSIT: //¿‘±›
                Deposit(C, index);
                break;
            case WITHDRAW:
                Withdraw(C, index);
                break;
            case INQUIRE:
                Inquire(C, index);
                break;
            case EXIT:
                Cleanup(C, index);
                return 0;
            default:
                cout << "º±≈√¿Ã ∆≤∑»Ω¿¥œ¥Ÿ." << endl;
                break;
                
        }//switch(choice)
    }//while(true)
    return 0;
}

void PrintMenu() {
    cout << "---------------MENU-----------------" << endl;
    cout << "1(∞Ë¡¬∞≥º≥)" << endl;
    cout << "2(¿‘±›)" << endl;
    cout << "3(√‚±›)" << endl;
    cout << "4(¿¸√º¡∂»∏)" << endl;
    cout << "5(«¡∑Œ±◊∑•¡æ∑·)" << endl;
}

void MakeAccount(Account** C, int& index) {
    if (index < ACT_MAX) {
        int id, bal;
        char name[NAME_LEN];
        cout << "∞Ë¡¬∞≥º≥¿ª ¿ß«— ¿‘∑¬(∞Ë¡¬id ¿‹æ◊ ¿Ã∏ß): "; //∞¥√º ¿Œ¿⁄¿÷¥¬ ª˝º∫¿⁄∏¶ ∫“∑Ø heap∏ﬁ∏∏Æ∏¶ »Æ∫∏«ÿæﬂ«‘
        cin.ignore();
        cin >> id >> bal >> name;
        for (int i = 0; i++; i < ACT_MAX) {
            if (strcmp(C[i]->GetName(), name) == 0) {
                cout << "중복되는 아이디 입니다. 새로운 아이디를 입력하십시오." << endl;
                cout << "계좌개설을 위한 입력(계좌id 잔액 이름): ";
                cin >> id >> bal >> name;
            }
            else
                break;
        }//for(int i=0; i++; i<ACT_MAX)
        
        C[index] = new Account(id, bal, name);
        /*(C[index])->SetId(id);
         (C[index])->SetBalance(bal);
         (C[index])->SetName(name); */
        index++;
        cout << endl;
    }
    else
        cout << "√÷¥Î " << ACT_MAX << "∞≥¿« ∞Ë¡¬∏¶ ∏∏µÈ ºˆ ¿÷Ω¿¥œ¥Ÿ." << endl;
}

void Deposit(Account** C, int index) {
    //∞Ë¡¬id, ¿‘±›æ◊ πØ±‚
    //∑Á«¡∏¶ ¿ÃøÎ«œø© id¿« ¡∏¿Áø©∫Œ »Æ¿Œ
    //»Æ¿Œµ«æ˙¿∏∏È InMoney()«‘ºˆ ∫Œ∏£±‚
    int m;
    int id;
    cout << "∞Ë¡¬ id: ";
    cin >> id;
    cout << "¿‘±›æ◊: ";
    cin >> m;
    int bal;
    bool found = false; //¿œƒ°«œ¥¬ id∞° ¿÷¥¬¡ˆ »Æ¿Œ
    
    for (int i = 0; i < index; i++) {
        if (id == C[i]->GetId()) {
            bal = C[i]->InMoney(m);
            cout << "«ˆ¿Á ¿‹∞Ì: " << bal << endl;
            found = true;
            break;
        }
    }//for(int i=0; i< index; i++)
    if (found == false) {
        cout << "¡∏¿Á«œ¡ˆ æ ¥¬ ID¿‘¥œ¥Ÿ." << endl;
    }
}

void Withdraw(Account** C, int index) {
    int m;
    int id;
    cout << "∞Ë¡¬ id: ";
    cin >> id;
    cout << "√‚±›æ◊: ";
    cin >> m;
    int bal;
    bool found = false; //¿œƒ°«œ¥¬ id∞° ¿÷¥¬¡ˆ »Æ¿Œ
    
    for (int i = 0; i < index; i++) {
        if (id == C[i]->GetId()) {
            bool b = C[i]->OutMoney(m);
            if (b == true) {
                cout << "«ˆ¿Á ¿‹∞Ì: " << C[i]->GetBalance() << endl;
            }
            else {
                cout << "¿‹∞Ì∞° √Ê∫–«œ¡ˆ æ Ω¿¥œ¥Ÿ." << endl;
            }
            found = true;
            break;
        }
    }//for(int i=0; i< index; i++)
    if (found == false) {
        cout << "¡∏¿Á«œ¡ˆ æ ¥¬ ID¿‘¥œ¥Ÿ." << endl;
    }
}

void Inquire(Account** C, int index) {
    for (int i = 0; i < index; i++)
    {
        C[i]->ShowAllData();
    }
}

void Cleanup(Account** C, int index) {
    for (int i = 0; i < index; i++) {
        delete C[i];
    }
}