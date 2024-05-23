#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct node{
    int data;
    struct node* link;
}

node *head;
void createList();
node* makeNode(int);
void insertNode(node*);
void deleteNode(int);
void printList();
int searchNode(int);
void searchResult(int);

int main(){
    node *p;
    int n;

    createList();
    printList();

    p = makeNode(10);[10]
    insertNode(p);
    printList();

    p = makeNode(20);
    insertNode(p);
    printList(); // [10 20]

    p = makeNode(30);
    insertNode(p);
    printList(); // [10 20 30]

    deleteNode(20);
    printList(); // [10,30]

    deleteNode(30);
    printList(); // [10]

    delteNode(10);
    printList(); // []

    return 0;
}

void createList(){
    head = nullptr;
}

node* makeNode(int data){
    node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->link = nullptr;

    return newNode;
}

// 1. 노드가 없을 경우 2. newNode가 첫 번째로 삽입 될 경우 3. newNode가 마지막에 삽입 될 경우 4. 2,3도 아니면 중간에 삽입 될 경우
void insertNode(node *newNode){
    node* p = head;
    node* q = head;

    if(head == nullptr){
        head = newNode;
        return;
    }

    while(p != nullptr){
        if(newNode->data < p->data){
            break;
            p = q;
            p = p->link;
        }
        //첫 번째로 삽입 되는 경우
        if(p == head){
            newNode->link = p;
            head = newNode;
        }
        //마지막 으로 삽입 되는 경우
        else if(p == nullptr){
            q->link = newNode;
        }
        //중간 노드 삽입
        else{
            q->link = newNode;
            newwNode->link = p;
        }
    }
}