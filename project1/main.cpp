#include<iostream>
#include"time2.h"

using namespace std;

int main() {
	cout << "실행완료" << endl;
	Time day1(1, 40);
	Time day2(2, 30);
	
	day1.show();
	day2.show();

	Time total;
	total = day1.operator+(day2);
	total.show();

	return 0;
}