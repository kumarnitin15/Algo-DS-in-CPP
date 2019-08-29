#include <iostream> 
#include <vector>
using namespace std; 
  
int linear_search(vector<int> v, int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (v[i] == x) 
            return i; 
    return -1; 
} 
  
int main() 
{ 
    vector<int> v{ 2, 3, 4, 10, 40 }; 
    int x = 10; 
    int n = v.size(); 
    int result = linear_search(v, n, x); 
   (result == -1)? cout<<"Element is not present in array" 
                 : cout<<"Element is present at index " << result; 
   return 0; 
} 
