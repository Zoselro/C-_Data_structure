#include<iostream>
#include<queue>
#include<stack>
#include<list>
using namespace std;

int main(){
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(123);
    q.push(5);

    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    
    list<int> l;

    l.push_front(1);
    l.push_front(2);    
    l.push_front(30);

    
    return 0;
}