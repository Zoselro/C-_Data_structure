#include<iostream>
#include "Stock.h"

int main() {
	cout << "생성자를 이용해 객체 생성\n";
	Stock temp("Panda", 100, 1000);

	cout << "디폴트 생성자를 이용하여 객체 생성\n";
	Stock temp2;

	cout << "temp를 temp2에 대입\n";
	temp2 = temp;

	cout << "temp와 temp2 출력\n";
	temp.show();
	temp2.show();

	cout << "생성자를 이용하여 temp 내용 재설정\n";
	temp = Stock("Coding", 200, 1000);

	cout << "재설정된 temp 출력\n";
	temp.show();

	Stock s1("A", 10, 1000);
	Stock s2("B", 20, 1200);

	cout << "A와 B중 share_val이 큰 객체는\n";
	s1.topval(s2).show();

	s1.update(2000);

	cout << "A와 B중 share_val이 큰 객체는\n";
	s1.topval(s2).show();

	return 0;
}