/* 
    Question:
    Find the nth fibonacci number using recursion.
    Eg:
    Given n = 4
    Output = 3
*/


#include<iostream> 
using namespace std; 
  
int fib(int n) 
{ 
    if (n <= 1) 
        return n; 
    return fib(n-1) + fib(n-2); 
} 
  
int main () 
{ 
    int n = 4; 
    cout << fib(n); 
    return 0; 
} 