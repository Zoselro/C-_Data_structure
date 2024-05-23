#include<iostream>

using namespace std;

template <typename T, int MAX_SIZE>

class Stack{
private:
    T elements[MAX_SIZE]; // 배열을 이요하여 스택 요소 저장
    int topIndex; // 스택의 맨 위 요소를 가리키는 인덱스

public:
    Stack(){
        topIndex = -1; // topIndex = -1 로 초기화
    }
    bool empty(){
        return (topIndex == -1);
    }
    void top(){
        if(empty()){
            cout << "Stack is empty!! " << endl;
        }
    }

    void push(const T& value){
        if(topIndex == -1){
            elements[++topIndex] = value;
        }
    }

    void pop(){
        if(empty()){
            cout << "Stack is empty!!" << endl;
            return;
        }
        --topIndex;
    }
};

int main(){
    Stack<int, 5> s;
    s.push(10);
    s.push(20);

    return 0;
}
