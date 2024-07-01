#include<iostream>
#include"struct.h"

using namespace std;

int main() {

	NODE* p;

	createList();
	p = makeNode(10);
	insertNode(p);
	p = makeNode(20);
	insertNode(p);
	p = makeNode(15);
	insertNode(p);
	printList();
	deleteNode(15);
	printList();

	searchResult(searchNode(20));

	return 0;
}