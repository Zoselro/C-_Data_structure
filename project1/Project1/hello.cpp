#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char month[12];

	for (int i = 0; i < 10; i++) {
		month[i] = 65 + i;
		printf("month =  %c\n",month[i]);
	}
	return 0;
}