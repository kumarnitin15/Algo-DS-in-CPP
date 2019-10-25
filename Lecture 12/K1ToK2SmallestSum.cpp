#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int a[] = { 20, 8, 22, 4, 12, 10, 14 };
    int n = 7;
    int k1 = 3; 
    int k2 = 6;
    priority_queue<int, vector<int>, greater<int>> pq{a, a+n};

    int count = 0, sum = 0;
    while(count < k2){
        int el = pq.top();
        count++;
        if(count >= k1)
            sum += el;
        pq.pop();
    }

    cout << sum;
}
