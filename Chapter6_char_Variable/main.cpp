#include<iostream>
#include<string>
using namespace std;

int main(){
    char ch = 'a';
    int a = ch;
    string str1 = "abc";
    string str2 = "def";
    string str3 = str1 + ", " +str2;
    double pi = 3.141592653589793238;
    long double pi_ld = 3.141592653589793238;
    int b = 20;


    cout << "ch : " << ch << endl;
    cout << "int a : " << a << endl;
    
    cout << "-----------------" << endl;

    cout << str1 + ", " + str2 << endl;
    cout << str3 << endl;

    cout << "-----------------" << endl;

    cout << "b : " << a << endl;
    
    cout << sizeof(ch) << endl;
    cout << sizeof(a) << endl;
    cout << sizeof(str1) << endl;
    cout << sizeof(str3) << endl;
    cout << sizeof(pi) << endl;
    cout << sizeof(pi_ld) << endl;

    cout << "------------------" << endl;


    cout << str1.compare(str2) << endl;
    if(str1.compare(str2) == 0){
        cout << "같은 문자열" << endl;
    }else{
        cout << "다른 문자열" << endl;
    }

    cout << (str1+", "+str2).compare(str3) << endl;
    if((str1+", "+str2).compare(str3) == 0){
        cout << "같은 문자열" << endl;
    }else{
        cout << "다른 문자열" << endl;
    }
    
    if(str3.compare(str1 + ", " + str2) == 0 && str1.compare("abc") == 0){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

    return 0;
}