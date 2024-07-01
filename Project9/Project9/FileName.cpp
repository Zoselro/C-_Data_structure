#include<iostream>
using namespace std;

struct Time
{
	int hours;
	int mins;
};

//Time sum(Time*, Time*);
void showTime(Time);
Time sum(Time, Time);
int main() {
	Time day1 = {};
	Time day2 = {};

	cout << "day1의 시간 입력 : " << endl;
	cin >> day1.hours;
	cout << "day1의 분 입력 : " << endl;
	cin >> day1.mins;

	cout << "day2의 시간 입력 : " << endl;
	cin >> day2.hours;
	cout << "day2의 분 입력 : " << endl;
	cin >> day2.mins;

	//Time total = sum(&day1, &day2);
	Time total = sum(day1, day2);

	cout << "이틀 소요 시간 : ";
	showTime(total);

	return 0;
}

/*Time sum(Time* t1, Time* t2) {
	
	Time total;

	total.hours = t1->hours + t2->hours + (t1->mins + t2->mins) / 60;
	total.mins = (t1->mins + t2->mins) % 60;
	return total;
}*/

void showTime(Time t1) {
	cout << t1.hours << "시간, " << t1.mins << "분 입니다." << endl;
}


Time sum(Time t1, Time t2) {

	Time total;

	total.hours = t1.hours + t2.hours + (t1.mins + t2.mins) / 60;
	total.mins = (t1.mins + t2.mins) % 60;
	return total;
}