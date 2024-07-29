#include <iostream>

using namespace std;

class treeHeap {
private:
    int size;
	int* heap = new int[size];
    int heapCount = 0;

public:
	void insert(int elem);
	int find(int elem);
	int deleteNode(int data);
	void print();
    void swap(int& num1, int& num2);
	~treeHeap(){
		delete[] heap;
	}
};