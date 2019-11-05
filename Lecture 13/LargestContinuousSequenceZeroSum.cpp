#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void lszero(vector<int> &A) {
    unordered_map<int, int> mp;
    int sum = 0, n = A.size(), start = 0, end = -1;
    
    for(int i=0; i<n; i++){
        sum += A[i];
        if(sum == 0){
            start = 0;
            end = i;
        }
        else if(mp.find(sum) != mp.end()){
            if(i-mp[sum]-1 > end-start){
                start = mp[sum]+1;
                end = i;
            }
        }
        else
            mp[sum] = i;
    }

    for(int i=start; i<=end; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main(){
    vector<int> v{1, 2, -2, 4, -4};
    lszero(v);
}
