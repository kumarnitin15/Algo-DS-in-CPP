#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

string convert(string s){
    vector<int> tmp(26, 0);
    for(char ch : s){
        int index = ch - 'a';
        tmp[index]++;
    }
    string sortedStr = "";
    for(int i=0; i<26; i++){
        char ch = 'a' + i;
        while(tmp[i]--)
            sortedStr += ch;
    }
    return sortedStr;
}

void anagrams(const vector<string> &A) {
    unordered_map<string, vector<int>> mp;
    for(int i=0; i<A.size(); i++){
        string str = convert(A[i]);
        mp[str].push_back(i+1);
    }
    set<string> st;
    vector<vector<int> > ans;
    for(string s : A){
        string str = convert(s);
        if(st.find(str) == st.end()){
            ans.push_back(mp[str]);
            st.insert(str);
        }
    }
    for(vector<int> v : ans){
        for(int idx : v)
            cout << idx << " ";
        cout << endl;
    }
}

int main(){
    vector<string> strings{"cat", "dog", "god", "tca"};
    anagrams(strings);
}
