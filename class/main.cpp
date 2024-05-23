#include<iostream>

using namespace std;

class FIRE{
private:
    int n = 20;
protected:
    int b = 50;
    void function1();
public:
    int m = 30;
    void callfunction1(){
        function1();
    }
};

class FIREChild : public FIRE{
public:
    void function2();    
};

int main(){
    static int a = 40;
    FIRE k;
    FIREChild fc;
    cout << k.m << endl;
    k.callfunction1();
    fc.callfunction1();
    fc.function2();
    return 0;
}

// 부모클래스는 어떤 변수든 접근 가능
void FIRE::function1(){
    cout << n << endl;
    cout << b << endl;
    cout << m << endl;
}

//자식 클래스는 부모 클래스에 접근이 가능하지만 private 멤버는 접근 불가(상속 관계)
void FIREChild::function2() {
    // 자식 클래스에서는 부모 클래스의 protected 멤버인 b에 접근할 수 있음
    cout << "protected : " << b << endl; // 자식클래스는 부모클래스의 protected에 접근가능
    cout << "public : " << m << endl; // 자식클래스는 부모 클래스의 public에 접근 가능
//    cout << n << endl; 자식클래스는 부모클래스의 private 으로 선언한 변수에 접근 불가
}