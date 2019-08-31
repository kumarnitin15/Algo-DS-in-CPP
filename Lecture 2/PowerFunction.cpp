/* 
    Question:
    Find the power of a number using recursion (x^y).
    Eg:
    Given x = 2, y = 3
    Output = 3
*/

#include<iostream> 
using namespace std; 

int power(int x, int y){
    if(y == 0)
        return 1;
    return x * power(x, y-1);
}
  
int main() 
{ 
    int x = 2; 
    int y = 3; 
  
    cout << power(x, y); 
    return 0; 
} 