#include<iostream>
#include "treehead.h"

using namespace std;

int main() {
	binarySearchTree* bst = new binarySearchTree();
	bst->insert(5);
	bst->insert(2);
	bst->insert(3);
	bst->insert(4);
	bst->insert(1);
	bst->insert(6);
	bst->insert(7);
	
	bst->print(bst->getRoot());
	cout << '\n';

	bst->deleteNode(4);
	bst->deleteNode(3);
	bst->deleteNode(1);
	bst->deleteNode(1000);
	bst->print(bst->getRoot());



/*	cout << '\n';
	bst->insert(3);
	bst->print(bst->getRoot());
	cout << '\n';
	bst->insert(3);
	bst->print(bst->getRoot());
	cout << '\n';

//	bst->erase(bst->find(3));
	bst->print(bst->getRoot());
	cout << '\n';

	cout<<bst->find(3)->data;*/

    return 0;
}


