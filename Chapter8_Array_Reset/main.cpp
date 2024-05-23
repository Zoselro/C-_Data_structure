#include<iostream>

using namespace std;

int add(int x=, int y);

int main(){
    
    cout << add(1) << endl;

    return 0;
}

int add(int x, int y){
    return x + y;
}