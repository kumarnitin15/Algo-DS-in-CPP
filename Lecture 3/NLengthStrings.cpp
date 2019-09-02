/*
    Question:
    Given a character set, print all n length strings using the chars given.
    Eg:
    n = 2
    chars = {a, b, c}
    Output:
    aa
    ab
    ac
    ba
    bb
    bc
    ca
    cb
    cc
*/

#include <iostream>
using namespace std;

void find(int n, int k, char chars[], char ans[], int sz){
    if(n < 1){
        for(int i=0; i<sz; i++)
            cout << ans[i];
        cout << endl;
        return;
    }
    for(int i=0; i<k; i++){
        ans[n-1] = chars[i];
        find(n-1, k, chars, ans, sz);
    }
}

int main() {
    int n = 2, k = 3;
    char chars[k] = {'a', 'b', 'c'};
    char ans[n];
    find(n, k, chars, ans, n);
}
