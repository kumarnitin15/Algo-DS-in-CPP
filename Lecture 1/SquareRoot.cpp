/*
    Question: 
    Compute and return the square root of x. 
    If x is not a perfect square, return floor(sqrt(x)).
 */

#include <iostream>
using namespace std; 

int square_root(int n){

    // Checking for corner case
    if(n == 0 || n == 1)
        return n;

    // Initialize the start and end of binary search    
    int s = 1, e = n-1;

    // The answer will be in sqr
    int sqr;

    while(s <= e){
        int m = (s+e)/2;
        if(m <= n/m){
            sqr = m;
            s = m+1;
        }
        else
            e = m-1;
    }
    return sqr;
}
  
int main() 
{ 
    int n = 49;
    cout << "The integral square root of " << n << " is " << square_root(n); 
    
    return 0; 
} 