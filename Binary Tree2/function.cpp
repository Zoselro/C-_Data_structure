#include<iostream>
#include"treehead.h"
#include<queue>

using namespace std;
/// <summary>
/// BST에 새로운 원소 삽입
/// </summary>
/// <param name="elem(삽입할 원소)"></param>
queue<Node*> nodeQueue;

void binarySearchTree::insert(int elem) {
	Node* addNode = new Node();
    addNode->data = elem;
    addNode->leftChild = nullptr;
    addNode->rightChild = nullptr;
	
	//처음 삽입 할 노드
    if (root == nullptr) {
        root = addNode; // 트리가 비어있으면 루트에 삽입
        addNode->parent = nullptr;

		nodeQueue.push(addNode);
        return;
    }

	//현재 노드를 가리키는 노드(초기값 root노드)
	Node* curNode = root;

	while (1) {
		//인풋값이 현재 curNode가 가리키는 노드의 데이터값보다 작다면
		while (curNode->data > elem) {
			//curNode의 왼쪽자식이없다면 
			if (curNode->leftChild == nullptr) {
				//curNode의 왼쪽자식노드값 설정해주고 부모 자식값 다시설정
				addNode->data = elem;
				addNode->parent = curNode; // addNode의 부모노드는 curNode로 세팅
				addNode->leftChild = nullptr;
				addNode->rightChild = nullptr;
				curNode->leftChild = addNode;

				nodeQueue.push(addNode);
				return;
			}
			//왼쪽 자식이 존재하면
			else {
				//curNode가 자신의 왼쪽 자식노드를 참조하게함
				curNode = curNode->leftChild;
			}
		}
		//인풋값이 curNode가 가리키는 노드의 데이터값보다 같거나 크면 
		while (curNode->data <= elem) {
			//오른쪽자식값이 없다면 해당 자식노드에 추가
			if (curNode->rightChild == nullptr) {
				addNode->data = elem;
				addNode->parent = curNode; // addNode의 부모노드는 curNode로 세팅
				addNode->leftChild = nullptr;
				addNode->rightChild = nullptr;
				curNode->rightChild = addNode;

				nodeQueue.push(addNode);
				return;
			}
			//오른쪽 자식 존재하면 오른쪽 자식 노드 참조하게함
			else {
				curNode = curNode->rightChild;
			}
		}
	}
}

/// <summary>
/// 입력값을 찾는 함수
/// </summary>
/// <param name="elem(찾을 원소)"></param>
/// <returns>"원소 찾았다면 해당 원소 가리키는 포인터, 못 찾았다면 nullptr"</returns>
Node* binarySearchTree::find(int elem) {
	Node* curNode = root;

	while(curNode != nullptr){
		if(curNode->data == elem){
			return curNode;
		} else if(curNode->data > elem){
			curNode = curNode -> leftChild;
		}else{
			curNode = curNode -> rightChild;
		}
	}
	return nullptr;
}

int binarySearchTree::deleteNode(int data){
	Node* p = find(data);

	//노드가 존재하지 않을경우
	if(root == nullptr){
		cout << "노드가 비어있음" << endl;
		return -1;
	}

	if(p == nullptr){
		cout << "지울 노드를 찾을 수 없음" << endl;
		return -2;
	}

	int deleteData = p->data;

	//삭제 할 노드가 리프 노드라면
	if(p->leftChild == nullptr && p->rightChild == nullptr){
		if(p->parent->leftChild == p){
			p->parent->leftChild = nullptr;
		}
		else if(p->parent->rightChild == p){
			p->parent->rightChild = nullptr;
		}
		cout << "지워진 노드 : " << p->data << endl;
		delete(p);
	}

	//삭제 할 노드의 오른쪽 자식이 존재 할 경우
	else if(p->leftChild == nullptr){
		p->parent->rightChild = p->rightChild;
		cout << "지워진 노드 : " << p->data << endl;
		delete(p);
	}
	//삭제 할 노드의 왼쪽 자식이 존재 할 경우
	else if(p->rightChild == nullptr){
		p->parent->leftChild = p->leftChild;
		cout << "지워진 노드 : " << p->data << endl;
		delete(p);
	}

	//삭제 할 노드의 자식이 둘 다 존재 할 경우
	//if(p->rightChild != nullptr && p->leftChild != nullptr){
	else{
		Node* q = p->rightChild;
		int deleteData = p->data;

		//오른쪽에서 가장 작은 값 탐색
		//오른쪽 서브트리의 루트노드부터 시작해서
		//오른쪽 서브트리의 제일 작은 노드까지 
		while (q->rightChild != nullptr) {
			q = q->leftChild;
		}

		p->data = q->data;
		
		// 제거
		if(q->parent->leftChild == q){
			q->parent->leftChild = q->leftChild;
		}
		else{
			q->parent->rightChild = q->rightChild;
		}

		if(q->rightChild != nullptr){
			q->rightChild->parent = q->parent;
		}
		cout << "지워진 노드 : " << p->data << endl;
		delete(q);
	}
	return deleteData;
}

/// <summary>
/// inorder 방식으로 순회하며 크기대로 출력
/// </summary>
/// <param name="root값 넣어주면 됨"></param>
void binarySearchTree::print(Node* node) {
	if (node == nullptr) return;
	print(node->leftChild);
	cout << node->data;
	print(node->rightChild);
}
//들어온 순서대로 출력해주는 함수
void binarySearchTree::print(){
	while(!nodeQueue.empty()){
		cout << nodeQueue.front() << ' ';
		nodeQueue.pop();
	}
}

/// <summary>
/// root노드 포인터 반환해주는 함수
/// </summary>
/// <returns>루트 노드</returns>
Node* binarySearchTree::getRoot() {
	return root;
}