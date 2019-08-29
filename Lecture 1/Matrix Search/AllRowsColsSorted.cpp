/*
    Question: 
    Given a matrix with every row and column of the matrix is sorted.
    Find whether a given element exists in the matrix or not.
    Eg. 
    Given matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {12, 30, 34, 50}}, x = 12
    output = Element is present in the matrix.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

bool staircase_search(vector<vector<int>> v, int x){
    int rows=v.size(), cols=v[0].size();

    // Starting at the left bottom of the matrix
    int sx=rows-1, sy=0;
    while(sx>=0 && sy<cols){
        if(v[sx][sy] == x)
            return true;
        if(v[sx][sy] < x)
            sy++;
        else
            sx--;
    }
    return false;
}
  
int main() 
{ 
    vector<vector<int>> v{{1, 3, 5, 7}, {10, 11, 16, 20}, {12, 30, 34, 50}};
    int x = 12;
    bool found = staircase_search(v, x);
    found == false ? cout << "Element not found" : cout << "Element is present in the matrix";
    return 0; 
} 