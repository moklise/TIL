#include<iostream>
using namespace std;
class Person {
protected:
    char *name;
    char *address;
    char *phone;
public:
    Person(char *name, char *address, char *phone);
    Person( );
    virtual void print( );
};

Person::Person(char *name, char *address, char *phone)
{
    
}

Person::Person( )
{
    
}

void Person::print( )
{
    cout<<"이름\t:"<<this->name<<endl;
    cout<<"주소\t:"<<this->address<<endl;
    cout<<"휴대폰번호:"<<this->phone<<endl;
}

class Customer:public Person {
private:
    char *id;
    int point;
public:
    Customer(char *name, char *address, char *phone, char *id, int _point);
    Customer( );
    void print( );
};

Customer::Customer(char *name, char *address, char *phone, char *id, int _point)
    :Person(name, address, phone)
{
    this->point = _point;
}



Customer::Customer( )
{
    
}

void Customer::print( )
{
    cout<<"이름\t:"<<this->name<<endl;
    cout<<"주소\t:"<<this->address<<endl;
    cout<<"휴대폰번호:"<<this->phone<<endl;
    cout<<"아이디:\t"<<this->id<<endl;
    cout<<"포인트 점수:"<<this->point<<endl;
}

int main( )
{
    Customer customer("손동복", "잠실", "01078459685", "kiko02", 0);
    customer.print( );
    
    return 0;
}