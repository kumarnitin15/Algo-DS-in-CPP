/*
    Question:
    Print all binary strings of length n.
    Eg:
    n = 2
    Output:
    00
    01
    10
    11
*/

#include <iostream>
#include <vector>
using namespace std;

void binary(int n, char ans[], int sz){
    if(n < 1){
        for(int i=0; i<sz; i++)
            cout << ans[i];
        cout << endl;
        return;
    }
    ans[n-1] = '0';
    binary(n-1, ans, sz);
    ans[n-1] = '1';
    binary(n-1, ans, sz);
}

int main() {
    int n = 2;
    char ans[n];
    binary(n, ans, n);
}
