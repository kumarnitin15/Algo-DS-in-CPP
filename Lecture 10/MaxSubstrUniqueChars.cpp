/*
    Question: Given a string find the maximum length of the substring having unique characters.
*/

#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

void maxLengthNonRepeatingSubstr(string s){
    
    int n = s.length();

    if(n == 0){
        cout << "0";
        return;
    }
    
    int a[26] = {0}; 
    int start = 0, end = 0, maxLen = 1;
    deque<char> q;

    for(int i=0; i<n; i++){
        int idx = s[i] - 'a';
        if(a[idx] == 0){
            a[idx] = 1;
            end = i;
        }
        else {
            maxLen = max(maxLen, end-start+1);
            while(s[start] != s[i]){
                int idx = s[start] - 'a';
                a[idx] = 0;
                start++;
            }
            start++;
            end++;
        }
    }
    maxLen = max(maxLen, end-start+1);
    cout << maxLen;
}

int main() {
    string str = "abcgdesdjfsaha";
    maxLengthNonRepeatingSubstr(str);
}