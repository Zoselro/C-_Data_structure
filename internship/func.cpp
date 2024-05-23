#include<iostream>
#include"time.h"
using namespace std;

Time::Time(){
    hour = mins = 0;
}

Time::Time(int h, int m){
    hour = h;
    mins = m;
}

void Time::Timeadd(int h, int m){
    mins += m;
	hour = (hour + (mins / 60)) + h;
	mins %= 60;
}

Time Time::Timeadd(Time t1, Time t2){
    Time sum;
    mins = (t1.mins + t2.mins) % 60;
    hour = t1.hour + t2.hour + ((t1.mins + t2.mins) / 60);
    sum.hour = hour;
    sum.mins = mins;
    return sum;
}

void Time::show(){
    cout << "시간 : " << hour << endl;
    cout << "분 : " << mins << endl;
}

Time::~Time(){

}