#include <iostream>

struct Node {
	int data;
	//부모 노드
	Node* parent;
	//왼쪽 자식 노드
	Node* leftChild;
	//오른쪽 자식 노드
	Node* rightChild;
};

class binarySearchTree {
private:
	Node* root = new Node();

public:
	binarySearchTree() {
		root = nullptr;
	}
	void insert(int elem);
	Node* find(int elem);
	int deleteNode(int data);
	void print(Node* node);
	Node* getRoot();
	void print();
};