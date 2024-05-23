#include<iostream>
using namespace std;

int s = 0;

template <typename Any>
Any add(Any,Any);
template <typename Any>
Any sub(Any,Any);
template <typename Any>
Any mul(Any,Any);
template <typename Any>
Any div(Any,Any);
template <typename Any>
Any mod(Any,Any);


int main(){

int s = 9999;

int st = 0;
cout << "st 입력 : ";
cin >> st;

    switch(st){
        case 1:
            add<double>(33.123,34);
            break;
        case 2:
            sub<double>(33,11);
            break;
        case 3:
            div<double>(33,11);
            break;
        case 4:
            mod(22,33);
            break;
        default:
            cout << "값을 잘못 입력" << endl;
            break;
    }
    
    cout << "s : " << s << endl;
    cout << "::s : " << ::s << endl;
    return 0;
}

template <typename Any>
Any add(Any x, Any y){
    cout << x + y << endl;
    return x + y; 
}

template <typename Any>
Any sub(Any x, Any y){
    cout << x - y << endl;
    return x - y;
}

template <typename Any>
Any mul(Any x, Any y){
    cout << x - y << endl;
    return x * y;
}

template <typename Any>
Any div(Any x, Any y){
    if(y == 0){
        cout<< "Error : 0으로 나눌 수 없습니다" << endl;
        return -1;
    }else{
        cout << x / y << endl;
    }
    return x / y;
}

template <typename Any>
Any mod(Any x, Any y){
    if(y == 0){
        cout<< "Error : 0으로 나눈 값의 나머지를 구할 수 없습니다." << endl;
        return -1;
    }else{
        cout << x % y << endl;
    }
    return x % y;
}