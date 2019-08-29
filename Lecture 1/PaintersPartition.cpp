/*
    Question: 
    You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. 
    There are K painters available and you are also given how much time a painter takes to paint 1 unit of board. 
    You have to get this job done as soon as possible under the following constraints:
    - 2 painters cannot share a board to paint.
    - A painter will only paint contiguous boards.
    Eg. 
    K : 2
    T : 5
    L : [1, 10]
    output = The minimum time required is 50
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std; 

bool isPossible(vector<int> &L, int n, int k, int curr_min) 
{ 
    int paintersRequired = 1; 
    int curr_sum = 0; 
    for (int i = 0; i < n; i++) 
    { 
        if (L[i] > curr_min) 
            return false; 
        if (curr_sum + L[i] > curr_min) 
        { 
            paintersRequired++; 
            curr_sum = L[i]; 
            if (paintersRequired > k) 
                return false; 
        } 
        else
            curr_sum += L[i]; 
    } 
    return true; 
}
  
int main() 
{ 
    vector<int> L{1, 10};
    int n = L.size(), k = 2, t = 5;
    long long sum = 0; 
    for (int i = 0; i < n; i++) 
        sum += L[i]; 
    long int start = 0, end = sum; 
    long int result = INT_MAX; 
    while (start <= end) 
    { 
        int mid = (start + end) / 2; 
        if (isPossible(L, n, k, mid)) 
        { 
            result = result <= mid ? result : mid; 
            end = mid - 1; 
        } 
        else
            start = mid + 1; 
    } 
    cout << "The minimum time required is " << result*t;
    return 0; 
} 