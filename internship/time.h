#include <iostream>
#ifndef TIMEH
#define TIMEH

class Time{
private:
    int hour;
    int mins;

public:
    Time();
    Time(int, int);
    void Timeadd(int, int);
    Time Timeadd(Time, Time);
    void show();
    ~Time();
};

#endif