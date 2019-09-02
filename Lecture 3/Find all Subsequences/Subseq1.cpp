/*
    Question:
    Print all subsequences of array, given all the elements are unique.
    Eg:
    v = {5, 10}
    Output:
    * Empty subsequence *
    10
    5
    5 10
*/

#include <iostream>
#include <vector>
using namespace std;

void findSubsequences(vector<int> v, int pos, vector<int> ans){
    int n = v.size();
    if(pos >= n){
        for(int i=0; i<ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
        return;
    }
    
    // Exclude the current element
    findSubsequences(v, pos+1, ans);

    // Include the current element
    ans.push_back(v[pos]);
    findSubsequences(v, pos+1, ans);
}

int main() {
    vector<int> v{5, 10};
    vector<int> ans;
    findSubsequences(v, 0, ans);
}
