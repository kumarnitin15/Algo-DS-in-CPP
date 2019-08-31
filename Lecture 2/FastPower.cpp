/* 
    Question:
    Find the power of a number using recursion (x^y).
    Solve the question in log time complexity.
    Eg:
    Given x = 2, y = 3
    Output = 3
*/

#include<iostream> 
using namespace std; 

int power(int x, int y) 
{ 
    if (y == 0) 
        return 1;
    int p = power(x, y/2);
    if (y % 2 == 0) 
        return p*p; 
    return x*p*p; 
} 
  
int main() 
{ 
    int x = 2; 
    int y = 5; 
  
    cout << power(x, y); 
    return 0; 
} 