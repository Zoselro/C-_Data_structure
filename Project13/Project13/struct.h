#ifndef STRUCT
#define STRUCT
typedef struct node {
	int data;
	struct node* link;
}NODE;

void createList();
NODE* makeNode(int);
void insertNode(NODE*);
void deleteNode(int);
void printList();
int searchNode(int);
void searchResult(int);
#endif
