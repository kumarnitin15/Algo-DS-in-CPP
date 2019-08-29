#include <iostream> 
#include <vector>
#include <cmath>
using namespace std; 

int jump_search(vector<int> arr, int n, int x) 
{ 
    // Setting the initial step
    int step = sqrt(n); 
  
    // Finding the sqrt(n) sized interval where element is present (if it is present) 
    int prev = 0; 
    while (arr[min(step, n)-1] < x) 
    { 
        prev = step; 
        step += sqrt(n); 
        if (prev >= n) 
            return -1; 
    } 
    // Doing a linear search for x in block beginning with prev. 
    while (arr[prev] < x) 
    { 
        prev++; 
  
        // If we reached next block or end of array, element is not present. 
        if (prev == min(step, n)) 
            return -1; 
    } 
    // If element is found 
    if (arr[prev] == x) 
        return prev; 
  
    return -1; 
}
  
int main() 
{ 
    vector<int> v{ 2, 3, 4, 10, 40 }; 
    int x = 10; 
    int n = v.size(); 
    int result = jump_search(v, n, x); 
   (result == -1)? cout<<"Element is not present in array" 
                 : cout<<"Element is present at index " << result; 
   return 0; 
} 