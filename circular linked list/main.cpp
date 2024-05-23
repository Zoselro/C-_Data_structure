#include "curPointer.h"
#include<iostream>
using namespace std;
int main(){
    curList cu;
    cu.insertNode(10);
    cu.insertNode(20);
    cu.insertNode(30);
    cu.insertNode(123);
    cu.deleteNode(10);
    cu.deleteNode(30);
    cu.deleteNode(20);
    cu.printList();
    return 0;
}