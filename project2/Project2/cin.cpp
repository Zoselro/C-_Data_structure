#include<iostream>
#include<cstring>

using namespace std;

int main() {
	char name1[15] = "";
	cout << name1 << "입니다.";
	//cin >> name1;
	cin.getline(name1, 15);
	cout << name1 << "입니다.";
	cout << "글자는 " << strlen(name1) << "자 입니다.";
	cout << "사이즈는 " << sizeof(name1) << "입니다.\n";

	string str1;
	string str2 = "sim";

	str1 = str2;

	cout << str1[0] << endl;

	return 0;
}