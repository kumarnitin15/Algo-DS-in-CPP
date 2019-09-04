#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &a, int l, int m, int r){
    int i=l, j=m+1;
    vector<int> t;

    while(i <= m && j <= r){
        if(a[i] <= a[j]){
            t.push_back(a[i]);
            i++;
        }
        else{
            t.push_back(a[j]);
            j++;
        }
    }
    while(i <= m){
        t.push_back(a[i]);
        i++;
    }
    while(j <= r){
        t.push_back(a[j]);
        j++;
    }
    for(int itr=0; itr<t.size(); itr++)
        a[itr+l] = t[itr];
}

void mergeSort(vector<int> &a, int l, int r){
    if(l < r){
        int m = (l+r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}

int main() {
    vector<int> a{5, 3, 6, 2, 18, 4};
    int n = a.size();

    mergeSort(a, 0, n-1);

    for(int i=0; i<n; i++)
        cout << a[i] << " ";
}
