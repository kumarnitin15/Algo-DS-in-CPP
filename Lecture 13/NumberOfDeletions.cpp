#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int mostFreq(vector<int> v){
    unordered_map<int, int> mp;
    int maxFreq = 0;

    for(int ele : v){
        if(mp.find(ele) != mp.end()){
            mp[ele]++;
        }
        else
            mp[ele] = 1;
        if(mp[ele] > maxFreq)
            maxFreq = mp[ele];
    }
    return maxFreq;
}

int main(){
    vector<int> v{2,4,5,7,8,9,9,9};
    int maxFreq = mostFreq(v);
    int n = v.size();
    int numDeletions = n-maxFreq;
    cout << "Number of deletions = " << numDeletions << endl;
}
