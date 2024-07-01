#include<iostream>
using namespace std;


struct Drink {
	string name;
	int price;
};


class machine {
private:
	Drink drinks[4] = { 
		{"콜라", 2000}, {"사이다", 1800}, 
		{"밀키스", 2200}, {"포도주스",1500} 
	};
	int money;
	int tot;
public:
	machine();
	machine(int, int);
	void searchName(string);
	void changeMoney(string, int);
};

machine::machine() {
	money = tot = 0;
}

machine::machine(int n, int m) {
	money = n;
	tot = m;
}

int main() {

	machine machine;
	machine.changeMoney("포도주스", 2000);

	return 0;
}

void machine::searchName(string n) {
	int cnt = sizeof(drinks) / sizeof(drinks[0]);

	for (int i = 0; i < cnt; i++) {
		if (drinks[i].name == n) {
			cout << "음료 이름 : " << drinks[i].name << ", 가격 : " << drinks[i].price << "입니다.\n";
		}
		else{
			cout << "음료가 존재하지 않습니다.\n";
			return;
		}
	}
}
/*
	음료 가격 이상의 money를 갖고 있고, 올바른 음료를 선택했을 때
	음료 가격 미만의 money를 갖고 있고, 올바른 음료를 선택했을 때
	올바르지 않은 음료를 선택 했을 때
*/

void machine::changeMoney(string n, int money) {
	int cnt = sizeof(drinks) / sizeof(drinks[0]);

	for (int i = 0; i < cnt; i++) {
		if (drinks[i].name == n && drinks[i].price <= money) {
			money -= drinks[i].price;
			cout << "남은 금액은 " << money << "입니다. " << endl;
			return;
		}
		else if (drinks[i].name == n && drinks[i].price > money) {
			cout << "지불 할 돈이 부족합니다." << endl;
			return;
		}
		else if (drinks[i].name != n){
			cout << "음료가 존재하지 않습니다." << endl;
			return;
		}
		else {
			cout << "Error" << endl;
		}
	}

}