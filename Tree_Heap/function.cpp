#include <iostream>
#include "heap.h"

void treeHeap::insert(int elem){
    heap[++heapCount] = elem;
    int child = heapCount;
    int parent = child / 2;
    
    while(child > 1 && heap[child] > heap[parent]){
        swap(heap[child], heap[parent]);
        child = parent;
        parent = child/2;
    }
}

void treeHeap::swap(int& num1, int& num2){
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
}

int treeHeap::find(int elem){

    for(int i = 0 ; i < heapCount ; i ++){
        /*if (heap[i] == elem){
            return i;
        }*/
        cout << heap[i] << endl;
    }
    return -1;
}

int treeHeap::deleteNode(int data){
    return 0;
}

void treeHeap::print(){

}