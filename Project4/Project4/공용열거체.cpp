#include <iostream>

using namespace std;
int main() {

	//공용체(Union)
	//서로 다른데이터형을 한 번에 한 가지만 보관할 수 있음.
	union MyUnion {
		int intval;
		long longVal;
		float floatVal;
	};

	MyUnion test;
	test.intval = 3;
	cout << test.intval << endl;
	test.longVal = 13;
	cout << test.intval << endl;
	cout << test.longVal<< endl;
	test.floatVal = 3.3;
	cout << test.intval << endl;
	cout << test.longVal << endl;
	cout << test.floatVal << endl;
	
	//열거체(enum)
	//기호 상수를 만드는 것에 대한 또다른 방법.
	

/*	enum spectrum { red, orange, yellow, green, // red = 0, orange = 1, yellow = 2 
	blue, violet, indigo, ultraviolet};*/

	enum spectrum {
		red = 3, orange = 5 , yellow = 7 , green = 9,
		blue = 11, violet = 13, indigo = 15, ultraviolet = 17
	}; // 임의로 상수를 지정하여 사용 할 수 있다.

	spectrum a = orange;
	
	cout << a << endl;

	int b;
	b = blue;
	b = blue + 3;

	int c = yellow;

	cout << b+c << endl;

	return 0;
}