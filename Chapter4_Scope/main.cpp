#include<iostream>

using namespace std;

int factory(int);
int fibonacci(int);
int func(int);
class A{
    public:
        int n1 = 20;
        static int n2;
        const int n3 = 40;
};


int A::n2 = 0;

int main(){
    A obj;
    cout << "obj.n1 : " << obj.n1 << endl;
    obj.n1 = 30;
    cout << "바꾼 후 obj.n1 : " << obj.n1 << endl;

    obj.n2 = 999;
    cout << "obj.n2 : " << obj.n2 << endl;

    //obj.n3 = 1234;
    //cout << "obj.n3" << obj.n3 << endl;
    factory(10);

    cout << fibonacci(8) << endl;

        cout << func(10) << endl;

   return 0;
}

int func(int n){
    if(n == 0){
        return 3;
    }
    if(n == 1)
        return 2;
    return func(n-1) + func(n-2);
}

int factory(int n){
    if(n == 1){
        cout << "n의 값 : " << n << endl;
        return n;
    }
    else if(n <= 0){
        cout << "n의 값 : " << n << endl;
        factory(n+1);
    }
    else if(n > 1){
        cout << "n의 값 : " << n << endl;
        factory(n-1);
    }
}

int fibonacci(int n){
    if(n == 1)
        return 1;

    if(n == 2)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
