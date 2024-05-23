#include<iostream>
#include"treehead.h"

using namespace std;

/// <summary>
/// BST에 새로운 원소 삽입
/// </summary>
/// <param name="elem(삽입할 원소)"></param>
void binarySearchTree::insert(int elem) {
	//새로 삽입할 노드
	Node* addNode = new Node;
	//맨처음 삽입이라면 루트에 넣어주기
	if (root == nullptr) {
		addNode->data = elem;
		addNode->parent = nullptr;
		addNode->leftChild = nullptr;
		addNode->rightChild = nullptr;
		root = addNode;
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
	//트리가 비어있다면 nullptr반환
	if (curNode == nullptr) {
		return nullptr;
	}
	while (1) {
		//현재 찾는값이 curNode가 가리키는 데이터값보다 작으면
		while (curNode->data > elem) {
			//왼쪽 자식노드로 
			curNode = curNode->leftChild;
		}
		//찾는 값이 curNode가 가리키는 데이터값보다 같거나 크면
		while (curNode->data <= elem) {
			//elem값을 찾았다면 해당 노드 반환
			if (curNode->data == elem) {
				return curNode;
			}
			//못찾았다면 오른쪽 노드로
			curNode = curNode->rightChild;
		}
		//curNode가 nullptr이라면 존재하지 않으므로
		if (curNode == nullptr) return nullptr;
	}
}

/// <summary>
/// 매개변수로 들어온 노드 두개 바꿔주는 함수
/// </summary>
/// <param name="a(노드 1)"></param>
/// <param name="b(노드 2)"></param>
/*void binarySearchTree::swap(Node* a, Node* b) {
	//swap용 임시 노드
	Node* tmp = new Node;
	//a의 부모 노드의 왼쪽자식이 a라면
	if (a->parent->leftChild == a) {
		//b로 연결
		a->parent->leftChild = b;
	}
	//a의 부모 노드의 오른쪽 자식이 b라면
	else {
		a->parent->rightChild = b;
	}

	//b의 부모 노드의 왼쪽 자식이 b라면
	if (b->parent->leftChild == b) {
		b->parent->leftChild = a;
	}
	//b의 부모 노드의 오른쪽 자식이 a라면
	else {
		b->parent->rightChild = a;
	}

	tmp->data = b->data;
	b->data = a->data;
	a->data = tmp->data;

	tmp->parent = b->parent;
	b->parent = a->parent;
	a->parent = tmp->parent;

	tmp->leftChild = b->leftChild;
	b->leftChild = a->leftChild;
	a->leftChild = tmp->leftChild;

	tmp->rightChild = b->rightChild;
	b->rightChild = a->rightChild;
	a->rightChild = tmp->rightChild;

	delete(tmp);
}*/

/// <summary>
/// BST에서 매개변수값 제거하는 함수
/// </summary>
/// <param name="elem(지울 원소)"></param>
/*void binarySearchTree::erase(int elem) {
	Node* delNode = find(elem);
	//BST에 해당 원소 없다면 바로 종료
	if (delNode == nullptr) {
		return;
	}
	//해당 원소가 리프 노드라면 : 자식이 없는 노드라면
	if (delNode->leftChild == nullptr && delNode->rightChild == nullptr) {
		//해당 원소의 부모노드에서 해당 원소 제거
		if (delNode->parent->leftChild == delNode) delNode->parent->leftChild = nullptr;
		else delNode->parent->rightChild = nullptr;
	}
	//해당원소가 오른쪽 자식만 있을 때
	else if (delNode->leftChild == nullptr) {
		//만약 del노드가 del의 부모노드의 왼쪽자식이라면
		if (delNode->parent->leftChild == delNode) {
			delNode->parent->leftChild = delNode->rightChild;
		}
		//del노드가 부모노드의 오른쪽자식이라면
		else {
			delNode->parent->rightChild = delNode->rightChild;
		}
		//해당원소의 오른쪽자식의 부모노드를 해당원소의 부모노드로 설정
		delNode->rightChild->parent = delNode->parent;
	}
	//해당원소가 왼쪽 자식만 있을 때
	else if (delNode->rightChild == nullptr) {
		//del노드가 부모 노드의 왼쪽자식이라면
		if (delNode->parent->leftChild == delNode) {
			//부모노드의 왼쪽 자식을 해당원소의 왼쪽 자식으로 설정
			delNode->parent->leftChild = delNode->leftChild;
		}
		else {
			delNode->parent->rightChild = delNode->leftChild;
		}
		//해당원소의 왼쪽자식의 부모노드를 해당원소의 부모노드로 설정
		delNode->leftChild->parent = delNode->parent;
	}

	//해당 원소가 두 자식 다 있을 때 오른쪽 서브트리에서 제일 작은값과 교체
	else if(delNode->rightChild != nullptr && delNode->leftChild != nullptr){
		//오른쪽 서브트리의 루트노드부터 시작해서
		Node* curNode = delNode->rightChild;
		//오른쪽 서브트리의 제일 작은 노드까지 
		while (curNode->leftChild != nullptr) {
			curNode = curNode->leftChild;
		}
		//두 노드를 바꿔주고
		swap(curNode, delNode);
		//해당 원소의 부모노드에서 해당 원소 제거
		if (delNode->parent->leftChild == delNode) delNode->parent->leftChild = nullptr;
		else delNode->parent->rightChild = nullptr;
	}
    //삭제할 원소가 루트 노드일 경우
    else{
        if(delNode == root){
            //루트 노드가 리프 노드일때
            if(delNode->leftChild == nullptr && delNode->rightChild == nullptr){
                root = nullptr;
            }
            //루트 노드가 오른쪽 자식만 있을 때
            else if(delNode->leftChild == nullptr){
                root = delNode->rightChild;
                root->parent = nullptr;
            }
            //루트 노드가 왼쪽 자식만 있을 때
            else if(delNode->rightChild == nullptr){
                root = delNode->leftChild;
                root->parent = nullptr;
            }
            //루트 노드가 두 자식 모두 다 있을 때
            else{
                Node* successor = delNode->rightChild;
                while(successor->leftChild != nullptr){
                    successor = successor->leftChild;
                }
                swap(delNode, successor);
                // 이제 delNode는 리프 노드 또는 하나의 자식만 있는 노드
                if(delNode->leftChild != nullptr){
                    delNode->parent->leftChild = delNode->leftChild;
                    delNode->leftChild->parent = delNode->parent;
                }
                else if(delNode->rightChild != nullptr){
                    delNode->parent->rightChild = delNode->rightChild;
                    delNode->rightChild->parent = delNode->parent;
                }
                else{
                    if (delNode->parent->leftChild == delNode) delNode->parent->leftChild = nullptr;
                    else delNode->parent->rightChild = nullptr;
                }
            }
        }
    }
	delete(delNode);
}*/

/// <summary>
/// 매개변수로 들어온 노드 포인터가 가리키는 노드 제거
/// </summary>
/// <param name="elem"></param>
/*void binarySearchTree::erase(Node* node) {
	//해당 원소가 리프 노드라면 
	if (node->leftChild == nullptr && node->rightChild == nullptr) {
		//해당 원소의 부모노드에서 해당 원소 제거
		if (node->parent->leftChild == node) node->parent->leftChild = nullptr;
		else node->parent->rightChild = nullptr;
	}
	//해당원소가 오른쪽 자식만 있을 때
	else if (node->leftChild == nullptr) {
		//만약 del노드가 del의 부모노드의 왼쪽자식이라면
		if (node->parent->leftChild == node) {
			node->parent->leftChild = node->rightChild;
		}
		//del노드가 부모노드의 오른쪽자식이라면
		else {
			node->parent->rightChild = node->rightChild;
		}
		//해당원소의 오른쪽자식의 부모노드를 해당원소의 부모노드로 설정
		node->rightChild->parent = node->parent;
	}
	//해당원소가 왼쪽 자식만 있을 때
	else if (node->rightChild == nullptr) {
		//del노드가 부모 노드의 왼쪽자식이라면
		if (node->parent->leftChild == node) {
			//부모노드의 왼쪽 자식을 해당원소의 왼쪽 자식으로 설정
			node->parent->leftChild = node->leftChild;
		}
		else {
			node->parent->rightChild = node->leftChild;
		}
		//해당원소의 왼쪽자식의 부모노드를 해당원소의 부모노드로 설정
		node->leftChild->parent = node->parent;
	}
	//해당 원소가 두 자식 다 있을 때 오른쪽 서브트리에서 제일 작은값과 교체
	else {
		//오른쪽 서브트리의 루트노드부터 시작해서
		Node* curNode = node->rightChild;
		//오른쪽 서브트리의 제일 작은 노드까지 
		while (curNode->leftChild != nullptr) {
			curNode = curNode->leftChild;
		}
		//두 노드를 바꿔주고
		swap(curNode, node);
		//해당 원소의 부모노드에서 해당 원소 제거
		if (node->parent->leftChild == node) node->parent->leftChild = nullptr;
		else node->parent->rightChild = nullptr;
	}
	delete(node);
}*/

int binarySearchTree::deleteNode(int data){
	Node* p = find(data);
	cout << "지울 노드 : " << p->data << endl;
	cout << "루트 노드 : " << root->data << endl;

	//노드가 존재하지 않을경우
	if(root == nullptr){
		cout << "노드가 비어있음" << endl;
		return -1;
	}

	if(p == nullptr){
		cout << "지울 노드를 찾을 수 없음" << endl;
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
		delete(p);
	}

	//삭제 할 노드의 오른쪽 자식이 존재 할 경우
	else if(p->leftChild == nullptr){
		p->parent->rightChild = p->rightChild;
		delete(p);
	}
	//삭제 할 노드의 왼쪽 자식이 존재 할 경우
	else if(p->rightChild == nullptr){
		p->parent->leftChild = p->leftChild;
	delete(p);
	}


	//삭제 할 노드의 자식이 둘 다 존재 할 경우
	if(p->rightChild != nullptr && p->leftChild != nullptr){
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

/// <summary>
/// root노드 포인터 반환해주는 함수
/// </summary>
/// <returns>루트 노드</returns>
Node* binarySearchTree::getRoot() {
	return root;
}