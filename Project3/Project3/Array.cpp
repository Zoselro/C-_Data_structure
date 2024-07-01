#include <iostream>

using namespace std;

int main() {

	struct MyStruct {
		string name;
		string position;
		float height;
		float weight;
	}B;


	B = {};

	cout << B.height << endl;

	MyStruct A[2] = {
		{"A", "A", 1, 1},
		{"B", "B", 2, 2}
	};

	cout << A[0].height << endl;

	return 0;
}