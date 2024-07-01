#include<iostream>
#include"struct.h"
#include"nodehead.h"

using namespace std;

void createList() {
	head = NULL;
}

NODE* makeNode(int data) {
	NODE* newNode = new NODE;
	newNode->data = data;
	newNode->link = NULL;

	return newNode;
}

void insertNode(NODE* newNode) {
	NODE* p = head;
	NODE* q = head;

	if (head == NULL) {
		head = newNode;
		return;
	}

	while (p != NULL) {
		if (newNode->data < p->data)
			break;

		q = p;
		p = p->link;
	}


	//first
	if (p == head) {
		newNode->link = p;
		head = newNode;
	}

	//Last
	else if (p == NULL) {
		q->link = newNode;
	}

	//중간노드삽입
	else {
		q->link = newNode;
		newNode->link = p;
	}
}

void deleteNode(int data) {
	NODE* p = head;
	NODE* q = p;

	if (p == NULL)
	{
		cout << "empty list!! \n " << endl;
		return;
	}

	while (p != NULL) {
		if (data == p->data)
			break;
		q = p;
		p = p->link;
	}

	if (p == NULL) {
		cout << ("no item\n") << endl;
		return;
	}

	//first
	if (p == head)
		head = p->link;
	//last
	else if (p->link == NULL)
		q->link = NULL;
	//middle
	else
		q->link = p->link;
	free(p);
}


void printList() {
	NODE* p = head;
	cout << "[";
	while (p != NULL) {
		cout << " " << p->data;
		p = p->link;
	}
	cout << "]\n" << endl;
}

int searchNode(int data) {
	NODE* p = head;
	int cnt = 0;

	while (p != NULL) {
		cnt++;
		if (data == p->data)
			break;
		p = p->link;
	}

	if (p == NULL) 
		cnt = -1;

	return cnt;
}

void searchResult(int data) {
	if (data == -1)
		cout << "no item \n" << endl;
	else
		printf("%d 번째 노드 \n", data);
}