#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void heapsort(vector<int> &v){
    
    priority_queue<int> pq;
    
    int n = v.size();

    for(int el : v)
        pq.push(el);

    for(int i=n-1; i>=0; i--){
        v[i] = pq.top();
        pq.pop();
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    heapsort(v);

    for(int el : v)
        cout << el << " ";
    cout << endl;
}