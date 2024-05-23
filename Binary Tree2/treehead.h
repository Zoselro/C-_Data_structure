#include<iostream>

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
	Node* root;
public:
	binarySearchTree() {
		root = nullptr;
	}
	void insert(int elem);
	Node* find(int elem);
	void swap(Node* a, Node* b);
	void erase(int elem);
	void erase(Node* elem);
	int deleteNode(int data);
	void print(Node* node);
	Node* getRoot();

};