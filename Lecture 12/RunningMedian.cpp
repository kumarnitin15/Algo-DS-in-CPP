#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    priority_queue<float> pq1;
    priority_queue<float, vector<float>, greater<float>> pq2;
    
    float tmp;
    float prevMedian = 0;
    while(cin >> tmp){

        // If the size of the max heap is greater than the size of the min heap
        if(pq1.size() > pq2.size()){
            if(tmp < prevMedian){
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(tmp);
            }

            else
                pq2.push(tmp);
            
            prevMedian = (pq1.top() + pq2.top()) / 2;
        }

        // If the size of the max heap is less than the size of the min heap
        else if(pq1.size() < pq2.size()){
            if(tmp < prevMedian)
                pq1.push(tmp);
            
            else {
                pq1.push(pq2.top());
                pq2.pop();
                pq2.push(tmp);
            }

            prevMedian = (pq1.top() + pq2.top()) / 2;
        }

        else {
            if(tmp < prevMedian){
                pq1.push(tmp);
                prevMedian = pq1.top();
            }
            
            else{
                pq2.push(tmp);
                prevMedian = pq2.top();
            }
        }
        cout << prevMedian << " ";
    }
}