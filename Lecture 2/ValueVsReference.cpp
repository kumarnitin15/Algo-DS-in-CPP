/* 
    Explaining call by value vs call by reference.
    swap(a, b) ; swap(&a, &b)
*/

#include <iostream> 
using namespace std; 

void swap1(int a, int b){
    int t = a;
    a = b;
    b = t;
}

void swap2(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
  
int main()  
{  
    int a = 3, b = 5;
    
    swap1(a, b);
    // Value of a and b would not change
    cout << a << " " << b << endl;

    swap2(a, b);
    // Value of a and b have been swapped
    cout << a << " " << b << endl;
    
    return 0;  
}