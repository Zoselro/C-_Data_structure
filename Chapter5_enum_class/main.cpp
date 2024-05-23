#include<iostream>

using namespace std;

enum class MyEnum{
    value1,
    value2,
    value3,
    value4
};


int main(){
    MyEnum myVar1 = MyEnum::value1;
    MyEnum* m1 = &myVar1;
    MyEnum** mm1 = &m1;

    MyEnum myVar2 = MyEnum::value2;
    MyEnum* m2 = &myVar2;
    MyEnum** mm2 = &m2;


    myVar1 = static_cast<MyEnum>(10);
//    cout << myVar1 << endl; // 명시적인 형변환 없이는 출력 할 수 없다.
    cout << static_cast<int>(myVar1) << endl;

    myVar2 = static_cast<MyEnum>('A');
//    cout << myVar2 << endl;
    cout << static_cast<char>(myVar2) << endl;

    cout << "-----Pointer-----" << endl;

    cout << static_cast<int>(*m1) << endl;
    cout << static_cast<char>(*m2) << endl;

    cout << "-----Double Pointer -----" << endl;

    cout << static_cast<int>(**mm1) << endl;
    cout << static_cast<char>(**mm2) << endl;
    
    return 0;
}