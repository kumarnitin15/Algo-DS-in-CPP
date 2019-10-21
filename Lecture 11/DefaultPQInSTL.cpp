#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void print(priority_queue<int> pq){
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main() {
    priority_queue<int> pq;

    for(int i=0; i<10; i++)
        pq.push(i);

    print(pq);
}