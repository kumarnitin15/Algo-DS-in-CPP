/*
    Question:
    Print all subsequences of array, given all the elements may be unique.
    You should only print the unique elements and in lexicographic order.
    Eg:
    v = {5, 10, 5}
    Output:
    * Empty subsequence *
    10
    5
    5 10
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void findSubsequences(vector<int> v, int pos, vector<int> ans, set<vector<int>> &st){
    int n = v.size();
    if(pos >= n){
        st.insert(ans);
        return;
    }
    
    // Exclude the current element
    findSubsequences(v, pos+1, ans, st);

    // Include the current element
    ans.push_back(v[pos]);
    findSubsequences(v, pos+1, ans, st);
}

int main() {
    vector<int> v{5, 10, 5};
    vector<int> ans; set<vector<int>> st;
    findSubsequences(v, 0, ans, st);

    for(vector<int> v : st){
        for(int i=0; i<v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
    }
}
