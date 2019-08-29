/*
    Question: 
    Given a matrix with every row of the matrix is sorted.
    Find whether a given element exists in the matrix or not.
    Eg. 
    Given matrix = {{10, 11, 16, 20}, {1, 3, 5, 7}, {23, 30, 34, 50}}, x = 23
    output = Element is present in the matrix.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

bool matrix_search(vector<vector<int>> v, int x){
    for(vector<int> t : v){
        // using an inbuilt function to perform binary search, present in the algorithm header file 
        if(binary_search(t.begin(), t.end(), x))
            return true;
    }
    return false;
}
  
int main() 
{ 
    vector<vector<int>> v{{10, 11, 16, 20}, {1, 3, 5, 7}, {23, 30, 34, 50}};
    int x = 23;
    bool found = matrix_search(v, x);
    found == false ? cout << "Element not found" : cout << "Element is present in the matrix";
    return 0; 
} 