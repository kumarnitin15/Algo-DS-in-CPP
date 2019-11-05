#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool isSubset(vector<int> v1, vector<int> v2){
    unordered_map<int, bool> mp;
    for(int ele : v2){
        mp[ele] = true;
    }
    for(int ele : v1){
        if(mp.find(ele) == mp.end())
            return false;
    }
    return true;
}

int main(){
    vector<int> v1{2,4,5,7,8,9};
    vector<int> v2{1,2,3,4,5,6,7,8,9,10};
    vector<int> v3{1,2,3,4,5};
    cout << isSubset(v1, v2) << endl << isSubset(v1, v3) << endl;
}
