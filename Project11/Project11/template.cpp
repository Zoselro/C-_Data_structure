#include<iostream>

using namespace std;

template <class T>
T sum(T, T);

template <class T>
T sum(int, T);

int main() {

	int a = 4;
	int b = 5;

	//cout << sum(a, b) << endl;
	float c = 3.14;
	float d = 1.592;
	cout << sum(c, d) << endl;
	cout << sum(a, c) << endl;
}

template <class T>
T sum(T a, T b) {
	return a + b;
}

template <class T>
T sum(int a, T b) {
	return a + b;
}