#include<iostream>
#include<list>

using namespace std;

int main() {
	list<int> L = { 3,7 };
	list<int>::iterator cur = L.begin();
	L.push_front(1);
	L.push_back(10);
	L.insert(cur, 5);
	cur++;

	for (cur = L.begin(); cur != L.end(); cur++) {
		printf("%d ", *cur);
	}

	return 0;
}