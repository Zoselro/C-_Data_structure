#include <iostream>
#include <cstdio>
using namespace std; // iostream에 정의되어있는 함수에 있는 std를 가져다 쓰기 위함
// 만약 using namespace std; 를 선언하지 않고 쓸 경우 std::cout << "hello, world! iostream" << std::endl 이런식으로 표현해야 되기 때문에
// 번거로울 수 있다.

int main() {

	printf("hello world! cstdio \n"); // c언어로 표현한 출력
	cout << "hello, world! iostream"; // 줄바꿈 x
	cout << "hello, world! iostream" << endl; /* endl 은 줄바꿈 즉, hello, world!iostream 라는 문자를 줄바꿈(endl)을 하면서
												cout(출력)해 달라는 의미 */
	return 0;
}