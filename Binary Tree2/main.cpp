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
	
	bst->deleteNode(4);
	bst->deleteNode(6);
	bst->deleteNode(7);
	bst->deleteNode(5);
	bst->deleteNode(1);
	bst->deleteNode(2);
	bst->deleteNode(3);
	bst->deleteNode(4);

    return 0;
}


