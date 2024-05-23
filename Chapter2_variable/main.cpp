#include<iostream>
//const : 상수 -> 한번 정의하면 프로그램이 실행되는 동안에는 값이 불변

using namespace std;

int func1();
static int func2();

int main(){
    const int a = -20; // 프로그램이 실행되는 동안 값 변경 불가
    double b = 20.1;
    float c = 20.234;
    char d = 'K';
    string e = "AAA";
    unsigned short s = 12; // 양수값만 출력 가능
    static int st = 30; // 특정 scope 내에 존재 하면 지역변수로 존재하더라도 전역변수처럼 사용 가능 함수가 종료되더라도 변수는 살아있음
    
    extern int num1;
    extern int num2;
    extern int num3;
    extern const int num4;

    cout << "int a : " << a << endl;
    cout << "double b : " << b << endl;
    cout << "float c : " << c << endl;
    cout << "char d : " << d << endl;
    cout << "string e : " << e << endl;
    cout << "unsigned short s : " << s << endl;
    cout << "St : " << st << endl;
    cout << "extern int num1 : " << num1 << endl;
    cout << "extern int num2 : " << num2 << endl;
    cout << "extern int num3 : " << num3 << endl;

//    cout << "extern int num3 : " << num3 << endl; // 에러 발생(static으로 선언된 변수를 불러오지 못함 -> static num3는 sum.cpp에서만 유효한 변수이기 때문)

    cout << "extern const int num4 : " << num4 << endl;

    // 여러번 실행 되더라도 static으로 선언된 값은 한 번만 초기화 한다.
    func1();
    // 초기화 후 지정했던 변수값을 기억한다.
    func1();

    int yy = func2();
    cout << "yy : " << yy << endl;

    yy = 90;
    cout << "yy : " << yy << endl;

    func2();

    return 0;
}

int func1(){
    static int k;
    cout << "static int k : " << k << endl; // static 변수는 같은 소스파일 내에서만 사용이 가능하고, 전역변수가 아닌 지역변수로 사용이 된다.
    k = 30;
    cout << "static int k : " << k << endl; // static 변수는 함수가 여러번 실행 되더라도 초기화는 한 번만 이루어진다.
    return k;
}

static int func2(){
    static int j;
    cout << "static int j : " << j << endl;
    j = 333;
    cout << "static int j : " << j << endl;
    return j;
}