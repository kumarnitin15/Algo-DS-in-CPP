#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class comparator {
    public:
        bool operator()(pair<int, int> p1, pair<int, int> p2){
            return p1.second > p2.second;
        }
};

vector<int> mergeArrays(vector<vector<int>> v){
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
    int k = v.size();
    vector<int> indices(k, 0);
    for(int i=0; i<k; i++){
        pq.push(make_pair(i, v[i][0]));
    }

    vector<int> ans;
    while(!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();
        int index = p.first;
        int element = p.second;
        ans.push_back(element);

        if(indices[index] < v[index].size()-1){
            pq.push(make_pair(index, v[index][indices[index]+1]));
            indices[index]++;
        } 
    }
    return ans;
}

int main() {

    int k;
    cin >> k;

    vector<vector<int>> v;

    for(int i=0; i<k; i++){
        int n;
        cin >> n;

        vector<int> tmp; int ele;
        for(int j=0; j<n; j++){
            cin >> ele;
            tmp.push_back(ele);
        }

        v.push_back(tmp);
    }
    vector<int> mergedArray = mergeArrays(v);

    for(int el : mergedArray)
        cout << el << " ";
    cout << endl;
}