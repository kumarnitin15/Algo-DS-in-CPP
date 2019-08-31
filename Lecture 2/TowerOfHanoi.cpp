/* 
    Question:
    Tower of Hanoi is a mathematical puzzle where we have three towers and n disks. 
    The objective of the puzzle is to move the entire stack to another tower, obeying the following simple rules:
    - Only one disk can be moved at a time.
    - Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack.
    - No disk may be placed on top of a smaller disk.
    Print the sequence of steps that would be followed for n disks.
    Eg:
    Given n = 3
    Output:
        Move disk 1 from tower A to tower B
        Move disk 2 from tower A to tower C
        Move disk 1 from tower B to tower C
        Move disk 3 from tower A to tower B
        Move disk 1 from tower C to tower A
        Move disk 2 from tower C to tower B
        Move disk 1 from tower A to tower B
*/

#include <iostream> 
using namespace std; 
  
void towerOfHanoi(int n, char src, 
                    char dest, char aux)  
{  
    if (n == 1)  
    {  
        cout << "Move disk 1 from tower " << src <<  
                            " to tower " << dest << endl;  
        return;  
    }  
    towerOfHanoi(n - 1, src, aux, dest);  
    cout << "Move disk " << n << " from tower " << src << 
                                " to tower " << dest << endl;  
    towerOfHanoi(n - 1, aux, dest, src);  
}  
  
int main()  
{  
    int n = 3;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;  
}