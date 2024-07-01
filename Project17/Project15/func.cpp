#include<iostream>
#include "Stock.h"


void Stock::buy(int n, float pr) {
	shares = shares - n;
	share_val = pr;
	set_total();
}

void Stock::sell(int n, float pr) {
	shares = shares + n;
	share_val = pr;
	set_total();
}

void Stock::update(float pr) {
	share_val = pr;
	set_total();
}
void Stock::show() {
	cout << "회사 명 : " << name << endl;
	cout << "주식 수 : " << shares << endl;
	cout << "주가 : " << share_val << endl;
	cout << "주식 총 가치 : " << tot_val << endl;
}

Stock &Stock::topval(Stock& s) {
	if (s.share_val > share_val) 
		return s;
	else return *this;
}

Stock::Stock(string co, int n, float pr) {
	name = co;
	shares = n;
	share_val = pr;
	set_total();
}
//오버로딩을 default생성자를 통한 값 초기화
Stock::Stock() {
	name = "";
	shares = 0;
	share_val = 0;
	set_total();
}


//파괴자 리턴값 갖지않고 선언된 데이터형과 매개변수도 갖을수 없다.
Stock::~Stock() {
	cout << name << "클래스 소멸. \n" << endl;
}