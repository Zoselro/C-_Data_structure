#include<iostream>
#include<thread>
#include <chrono>
using namespace std;

int countDown(int);
void countSecond(int);

int main() {
	cout << countDown << endl;

	int (*arc)(int);
	arc = countDown;
	
	arc(5);

	countSecond(5);

	return 0;
}

int countDown(int n) {
	cout << "Counting..." << n << endl;
	if (n > 0)
		countDown(n - 1);
	cout << n << "번째 재귀함수" << endl;
	return n;
}

void countSecond(int n) {
	cout << n << "초" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));
	if (n > 0) {
		countSecond(n - 1);
	}
}