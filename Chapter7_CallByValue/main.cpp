#include<iostream>

using namespace std;

//void swap(int*, int*);
//void swap(int, int);
void swap(int&, int&);

int main(){
    int a = 10;
    int b = 30;
    double f = 12.34f;
    double d = 12.34;
    string str = "aaaaaaa";
    double cc = 12.2l;
    char ch1[10] = {};
    char ch2[] = {'a','b','c'};

    cout << sizeof(ch1) << endl;
    cout << sizeof(ch2) << endl;
    cout << sizeof(f) << endl;
    cout << cc << endl;

    cout << "&a : " << &a << endl;
    cout << "&b : " << &b << endl;

    cout << "a : " << a << endl;
    cout << "b : " << b << endl;

//    swap(a,b);
//    swap(&a,&b);
    swap(a,b);

    cout << "&a : " << &a << endl;
    cout << "&b : " << &b << endl;


    cout << "a : " << a << endl;
    cout << "b : " << b << endl;

    return 0;
}

// 그대로 a, b 가 복사 된 후 연산이 이루어짐 (main에는 영향을 끼칠 수 없음)
/*void swap(int a, int b){
    int tmp = 0;

    cout << "swap(a,b) &a : " << &a << endl;
    cout << "swap(a,b) &b : " << &b << endl;

    tmp = a;
    a = b;
    b = tmp;

}

//그대로 a, b가 복사 됨, 이후 주소를 직접적으로 참조를 하면서 연산이 이루어짐. main 함수에 있는 값에 영향을 끼침
void swap(int* a, int* b){
    int tmp = 0;

    cout << "swap(&a,&b) &a : " << &a << endl;
    cout << "swap(&a,&b) &b : " << &b << endl;

    tmp = *a;
    *a = *b;
    *b = tmp;
}*/

void swap(int &a, int &b){
    int tmp = 0;

    cout << "swap(a,b) &a : " << &a << endl;
    cout << "swap(a,b) &b : " << &b << endl;

    tmp = a;
    a = b;
    b = tmp;
}