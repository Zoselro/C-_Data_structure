#include<iostream>

struct Node{
    Node* llink;
    int data;
    Node* rlink;
};

class curList{
private:
    Node* head;
public:
    curList(); // 생성자
    void insertNode(int value);
    void printList();
    void deleteNode(int value);
    ~curList(); // 소멸자
};