#include <iostream> 
#include <vector>
using namespace std; 

int binary_search(vector<int> arr, int l, int r, int x) 
{ 
    while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        // Check if x is present at mid 
        if (arr[m] == x) 
            return m; 
  
        // If x greater, go right
        if (arr[m] < x) 
            l = m + 1; 
  
        // If x is smaller, go left
        else
            r = m - 1; 
    } 
  
    // If we reach here, then element was not present 
    return -1; 
}
  
int main() 
{ 
    vector<int> v{ 2, 3, 4, 10, 40 }; 
    int x = 10; 
    int n = v.size(); 
    int result = binary_search(v, 0, n-1, x); 
   (result == -1)? cout<<"Element is not present in array" 
                 : cout<<"Element is present at index " << result; 
   return 0; 
} 