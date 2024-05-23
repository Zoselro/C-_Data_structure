#include<iostream>
#include"time.h"
using namespace std;

int main(){
    Time sum;
    const int size = 5;
    Time t[size] = {
        Time(1,20),
        Time(2,30),
        Time(3,40),
        Time(4,50),
        Time(5,50)
        };

    for(int i = 0 ; i < size-1 ; i++){
        if(i == 0)
            sum = sum.Timeadd(t[i], t[i+1]);
        
        else if(i > 0)
            sum = sum.Timeadd(sum,t[i+1]);      
    }
    sum.show();

    return 0;
}