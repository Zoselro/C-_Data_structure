#include<iostream>
using namespace std;

int main() {

	int val = 3;
	cout << "val의 주소 : " << & val << endl;

	int* p1 = &val;
	cout << "p1의 값 : " << *p1 << endl;

	int** p2 = &p1;
	cout << "*p2의 값 : " << *p2 << endl;
	cout << "p2의 값 : " << **p2 << endl;
	return 0;
}