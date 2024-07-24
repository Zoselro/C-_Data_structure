#include "curPointer.h"
#include <iostream>

using namespace std;

curList::curList(){
    head = nullptr;
}

void curList::insertNode(int value){
    //Node* newNode = (Node*)malloc(sizeof(Node));
    Node* newNode = new Node();
    
    //첫 노드 삽입
    if(head == nullptr){
        head = newNode;
        newNode->data = value;
        head->llink = head; // newNode->llink = head; 와 같은 의미
    }else{
        Node* temp = head;
        while (temp->llink != head){
            temp = temp->llink; // temp = head->llink;
        }
        temp->llink = newNode;
        newNode->data = value;
        newNode->llink = head;
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
        temp = temp->llink;
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
        p = p->llink;
    }while(p != head);

    if(found == false){
        cout << "삭제할 노드가 없습니다." << endl;
        return;
    }
    //삭제
    if(p == head){
        //노드가 한 개 일경우
        if(head->llink == head){
            delete p;
            head = nullptr;
        }
        else{
            //첫 번째 노드 삭제
            Node* lastNode = head;
            while(lastNode->llink != head){
                lastNode = lastNode->llink;
            }
                head = head->llink;
                lastNode->llink = head;
                delete p;
        } 
    }else {
    // 중간 노드 삭제
    q->llink = p->llink; // 이전 노드의 next를 다음 노드로 연결
    delete p; // 삭제할 노드 메모리 해제
    }
}

curList::~curList(){
}