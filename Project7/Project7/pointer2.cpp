#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

#define SIZE 20

int main() {

	using namespace std;

	char animal[SIZE];
	char* ps;

	cout << "동물 이름 : \n";
	cin >> animal;

	ps = new char[strlen(animal) + 1];
	strcpy(ps, animal);
	
	cout << "입력하신 동물이름을 복사하였습니다." << endl;
	cout << "입력하신 동물이름은 " << animal << "이고, 그 주소는 " << (int*)animal << &animal << " 입니다." << endl;
	cout << "복사된 동물 이름은 " << ps << "이고,그 주소는 " << (int*)ps << &ps << " 입니다." << endl;
	
	cout << "animal은 " << animal << endl;
	cout << "&animal은 변수 자체의 주소인 " << &animal << " 입니다." << endl;
	cout << "int(*animal)은 배열의 시작주소인 " << int(*animal) << " 입니다." << endl;
	cout << "ps 는 " << ps << endl;
	cout << "(int*)ps 는 new를 통해 동적으로할당된 주소인 " << (int*)ps << " 입니다." << endl;
	cout << "&ps 는 포인터 변수 자체의 주소인 " << &ps << " 입니다." << endl;


	struct MyStruct
	{
		char name[20];
		int age;
	};

		MyStruct* temp = new MyStruct;

		cout << "당신의 이름을 입력하십시오.\n";
		cin >> temp->name;

		cout << "당신의 나이를 입력하십시오.\n";
		cin >> (*temp).age;

		cout << "안녕하세요! " << temp->name << "씨!\n";
		cout << "당신은 " << temp->age << "살 이군요!\n";

		delete temp;

		MyStruct temp2;
		cout << "당신의 이름을 입력하십시오.\n";
		cin >> temp2.name;

		cout << "당신의 나이를 입력하십시오.\n";
		cin >> temp2.age;


		cout << "안녕하세요! " << temp2.name << "씨!\n";
		cout << "당신은 " << temp2.age << "살 이군요!\n";

		return 0;
	}