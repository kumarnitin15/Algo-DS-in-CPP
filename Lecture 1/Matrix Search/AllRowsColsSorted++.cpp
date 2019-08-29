/*
    Question: 
    Given a matrix with every row of the matrix is sorted.
    Every last element of a row is smaller than the first element of the next row.
    Find whether a given element exists in the matrix or not.
    Eg. 
    Given matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}}, x = 23
    output = Element is present in the matrix.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

bool matrix_search(vector<vector<int>> v, int x){
    int rows = v.size(), cols = v[0].size();
    int s=0, e=rows-1;
    while(s <= e){
        int m = (s+e)/2;
        if(v[m][0] > x)
            e = m-1;
        else if(v[m][cols-1] < x)
            s = m+1;
        else
            return  binary_search(v[m].begin(), v[m].end(), x);
    }
    return false;
}
  
int main() 
{ 
    vector<vector<int>> v{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    int x = 23;
    bool found = matrix_search(v, x);
    found == false ? cout << "Element not found" : cout << "Element is present in the matrix";
    return 0; 
} 