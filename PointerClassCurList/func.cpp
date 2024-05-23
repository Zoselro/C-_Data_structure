#include "curPointer.h"
#include <iostream>

using namespace std;

curList::curList(){
    head = nullptr;
}

void curList::insertNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    //첫 노드 삽입
    if(head == nullptr){
        head = newNode;
        newNode->data = value;
        head->next = head;
    }else{
        Node* temp = head;
        while (temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->data = value;
        newNode->next = head;
    }
}

void curList::printList(){
    if(head == nullptr){
        cout << "empty List !!" << endl;
        return;
    }
    Node* temp = head;
    do{ 
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
    cout << endl;
}

void curList::deleteNode(int value){
    Node* p = head; // 삭제할 노드
    Node* q = nullptr; // 이전 노드
    bool found = false;
    if(head == nullptr){
        cout << "empty List !!" << endl;
        return;
    }

    //삭제 노드 탐색
    do{
        if(p->data == value){
            found = true;
            break;   
        }
        q = p;
        p = p->next;
    }while(p != head);

    if(found == false){
        cout << "삭제할 노드가 없습니다." << endl;
        return;
    }
    //삭제
    if(p == head){
        if(head->next == head){
            delete p;
            head = nullptr;
        }
        else{
            Node* lastNode = head;
            while(lastNode->next != head){
                lastNode = lastNode->next;
            }
                head = head->next;
                lastNode->next = head;
                delete p;
        } 
    }else {
    // 중간 노드 삭제
    q->next = p->next; // 이전 노드의 next를 다음 노드로 연결
    delete p; // 삭제할 노드 메모리 해제
    }
}
curList::~curList(){
}