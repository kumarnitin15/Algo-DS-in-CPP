#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class comparator {
    public:
        bool operator()(char a, char b){
            return a > b;
        }
};

void print(priority_queue<char, vector<char>, comparator> pq){
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main() {
    priority_queue<char, vector<char>, comparator> pq;

    char ch = 'a';

    for(int i=0; i<10; i++)
        pq.push(ch+i);

    print(pq);
}