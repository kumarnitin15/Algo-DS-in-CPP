/*
    Question: 
    Find the pivot element in a rotated and sorted array.
    Eg. 
    Given array = {55, 23, 1, 78, 95, 103}
    ans = 1 is the pivot here.
 */

#include <iostream>
#include <vector>
using namespace std; 

int find_pivot(vector<int> v){

    int n = v.size();

    // Handling some corner cases
    if(n == 1)
        return -1;

    if(n == 2){
        if(v[1] < v[0])
            return 1;
        return -1;
    }

    // If the array is in descending order
    if(v[n-1] < v[0])
        return n-1;

    int s=0, e=n-1;

    while(s<=e){
        int m = (s+e)/2;

        // Check if m is the pivot
        if(m > 0 && m < n && v[m-1] > v[m] && v[m+1] > v[m])
            return m;

        if(v[m] > v[0])
            e = m-1;
        
        else
            s = m+1;
    }
    return -1;
}
  
int main() 
{ 
    vector<int> v{55, 23, 1, 78, 95, 103};
    cout << "Index of pivot element is " << find_pivot(v);
    return 0; 
} 