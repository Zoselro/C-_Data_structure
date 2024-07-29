#include <iostream>
#include "heap.h"

int main(){
    treeHeap* th = new treeHeap();

    th->insert(10);
    th->insert(20);
    th->insert(30);
    th->insert(40);
    cout << th->find(10) << endl;
    return 0;
}
