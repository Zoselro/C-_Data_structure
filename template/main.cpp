#include<iostream>

using namespace std;

//class 혹은 typename

//template <class Any>

template <typename Any>
Any Sum(Any, Any);


int main(){
    int a = 3;
    int b = 4;
    cout << Sum(a,b) << endl;

    float c = 3.14;
    float d = 1.592;
    cout << Sum(c,d) << endl;

    cout << Sum(a,(int)c) << endl;

    return 0;
}

template <typename Any>
Any Sum(Any a, Any b){
    return a+b;
}