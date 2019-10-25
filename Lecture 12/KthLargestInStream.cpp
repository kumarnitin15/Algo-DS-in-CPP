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

void print(priority_queue<int, vector<int>, greater<int>> pq){
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;

    int k;
    cin >> k;

    int inp;

    while(cin >> inp){
        if(pq.size() < k)
            pq.push(inp);

        else if(pq.top() < inp){
            pq.pop();
            pq.push(inp);
        }

        if(pq.size() < k)
            cout << "_ ";
        else  
            cout << pq.top() << " ";
    }
    cout << endl;

}