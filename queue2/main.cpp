#include <iostream>
using namespace std;
struct Node {
	int data;
	//부모 노드
	Node* parent;
	//왼쪽 자식 노드
	Node* leftChild;
	//오른쪽 자식 노드
	Node* rightChild;
};

int main(){
    Node * p = new Node();
    cout << p->leftChild << endl;

    return 0;
}