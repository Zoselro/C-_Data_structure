#include<iostream>
#include<string>
using namespace std;

int main() {
	char a = 'A';
	string b = "A";

	cout << static_cast<int>(a) << endl;

	for (int i = 0; i < static_cast<int>(a); i++) {
		cout << i+1 << " ¹øÂ°" << endl;
	}
}