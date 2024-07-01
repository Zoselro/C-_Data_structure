#include <iostream>
#ifndef TIMEH
#define TIMEH

class Time
{
private:
	int hours;
	int mins;

public:
	Time();
	Time(int, int);
	void addHours(int);
	void addMins(int);
	Time operator+(Time&);
//	Time operator*(int);
	virtual void show(); // virtual 가상메서드 (호출한 메서드의 객체를 따져서 그에따라 대응되는 함수를 선택)
	virtual ~Time();
	friend Time operator*(int, Time&);
	/*friend Time operator*(int n, Time& t) {
		return t * n;
	}*/
	int getHour() {
		return hours;
	}
	int getMins() {
		return mins;
	}
	friend std::ostream& operator << (std::ostream&, Time&);
};


class NewTime : public Time { // time이라는 오리지널 클래스로 NewTime 이라는 파생 클래스를 만든다. 
private:
	int day;
public:
	NewTime();
	NewTime(int, int, int);
	void show();
};

#endif