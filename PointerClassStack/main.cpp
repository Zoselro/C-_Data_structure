#include<iostream>

using namespace std;

// 스택 노드 정의
struct Node {
    int data;
    Node* next;
};

class Stack{
private:
    Node* top;
public:
    Stack(){
        top = nullptr; // 스택 초기화
    }

    int push(int value){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = top; // nullptr
        top = newNode;
        return newNode->data;
    }
    bool isEmpty(){
        return (top == nullptr);
    }
    void pop(){
        if(isEmpty()){
            cout << "Stack is Empty !!" << endl;
            return;
        }
        Node * temp = top;
        top = top->next;
        cout << temp->data << " 데이터 삭제" << endl;
        delete temp;
    }

    void printStack(){
        Node* cur = top;
        if(isEmpty()){
            cout << "Stack is Empty !!" << endl;
            return;
        }
        while(cur != nullptr){
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    //스택 메모리 해제
    ~Stack(){
        while(!isEmpty()){
            pop();
        }
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.printStack();
    return 0;
}