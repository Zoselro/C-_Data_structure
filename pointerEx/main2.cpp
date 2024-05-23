#include<iostream>

using namespace std;

int main(){
    int a[3] = {10,13,17};
    int *p[3];

    for (int i = 0; i < 3; ++i) {
        p[i] = &a[i];  // 각 포인터가 배열 a의 각 요소의 주소를 가리키도록 합니다.
    }

    cout << *p[0] << endl;

}