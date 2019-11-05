#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool compare(vector<int> v1, vector<int> v2){
    if(v1.size() == 0)
        return true;
    if(v1[1] == v2[1])
        return v1[0] > v2[0];
    return v1[1] > v2[1];
}

void twoSum(const vector<int> &A, int B) {
    
    unordered_map<int, vector<int>> mp;
    vector<int> ans;
    int n = A.size();
    
    for(int i=0; i<n; i++)
        mp[A[i]].push_back(i);
        
    for(int i=0; i<n; i++){
        int v1 = A[i];
        int diff = B - v1;
        if(mp.find(diff) != mp.end()){
            if((diff == v1) && (mp[diff].size() == 1) && (mp[diff][0] == i))
                continue;
            int idx1 = i;
            int idx2;
            if(diff == v1 && mp[diff][0] == i)
                idx2 = mp[diff][1];
            else
                idx2 = mp[diff][0];
            
            vector<int> tmp;
            
            idx1++;
            idx2++;
                
            if(idx1 < idx2){
                tmp.push_back(idx1);
                tmp.push_back(idx2);
            }
            
            else{
                tmp.push_back(idx2);
                tmp.push_back(idx1);
            }
            
            if(compare(ans, tmp))
                ans = tmp;      
        }
    }
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main(){
    vector<int> v{2, 7, 11, 15};
    int target = 9;
    twoSum(v, target);
}
