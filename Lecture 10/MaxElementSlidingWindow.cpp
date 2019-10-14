/*
    Question: Given an array find the maximum element in every subarray of size k.
*/

#include <iostream>
#include <deque>
using namespace std;

void maxElementSlidingWindow(int a[], int n, int k){
    deque<int> q;
    for(int i=0; i<k; i++){
        while(!q.empty() && a[i] >= a[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    for(int i=k; i<n; i++){

        cout << a[q.front()] << " ";
        
        while(!q.empty() && q.front() <= i-k)
            q.pop_front();
        
        while(!q.empty() && a[i] >= a[q.back()])
            q.pop_back();
        
        q.push_back(i);
    }
}

int main() {
    int a[10] = {6,4,3,7,5,9,12,10,8,1};
    int k = 3;
    maxElementSlidingWindow(a, 10, k);
}