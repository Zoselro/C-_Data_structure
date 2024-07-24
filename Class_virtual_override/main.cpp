#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() { // 가상 함수
        cout << "Display from Base class" << endl;
    }
};

class Derived : public Base {
public:
    void display() override { // 파생 클래스에서 가상 함수 재정의
        cout << "Display from Derived class" << endl;
    }
};

class Base2 {
    public:
        void print(){
            cout << "Base2 print" << endl;
        }
};

class Dervied2 : public Base2 {
    public:
        void print() {
            cout << "Dervied2 print" << endl;
        }
};

int main() {
    Base *b;
    Derived d;
    b = &d;

    Base2 * b2;
    Dervied2 d2;
    b2 = &d2;

    b->display(); // Derived 클래스의 display()가 호출됨
    b2->print();
    
    return 0;
}