/*
    Question: 
    Suppose a sorted array is rotated at some pivot unknown to you beforehand.
    You are given a target value to search. If found in the array, return its index, otherwise return -1.
    You may assume no duplicate exists in the array.
    Eg. 
    Given array = {55, 23, 1, 78, 95, 103}, x = 78
    ans = 3.
 */

#include <iostream>
#include <vector>
using namespace std; 

int rotated_sorted_search(vector<int> v, int x){
    int n = v.size();
    int s = 0, e = n-1;
    while(s <= e) {
        int m = (s+e)/2;
        if(v[m] == x)
            return m;
        if(v[m] > v[0]) {
            // in the right half
            if(x > v[0]) {
                if(x > v[m])
                    s = m+1;
                else
                    e = m-1;
            }
            else
                e = m-1;
        }
        else if(v[m] <= v[0]) {
            // in the left half
            if(x <= v[0]) {
                if(x > v[m])
                    e = m-1;
                else
                    s = m+1;
            }
            else
                s = m+1;
        }
    }
    return -1;
}
  
int main() 
{ 
    vector<int> v{55, 23, 1, 78, 95, 103};
    int x = 78;
    int result = rotated_sorted_search(v, x);
    result == -1 ? cout << "Element not found" : cout << "Element found at index " << result;
    return 0; 
} 