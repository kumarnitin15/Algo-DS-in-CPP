#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int blk_sz;

void update(int a[], int block[], int idx, int val){
    block[idx/blk_sz] = val - a[idx];
    a[idx] = val;
}

int query(int a[], int block[], int l, int r){
    int s = 0;
    while(l <= r && l%blk_sz != 0){
        s += a[l];
        l++;
    }
    while(l+blk_sz <= r){
        s += block[l/blk_sz];
        l = l + blk_sz;
    }
    while(l <= r){
        s += a[l];
        l++;
    }
    return s;
}

void preprocess(int a[], int n, int block[]){
    
    int blk_idx = -1;

    for(int i=0; i<n; i++){
        if(i % blk_sz == 0)
            blk_idx++;
        block[blk_idx] += a[i];
    }
}

int main() {
    int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 7}; 
    int n = sizeof(a)/sizeof(a[0]); 
    
    blk_sz = sqrt(n);
    int blks_cnt = (n/blk_sz)+1;
    int block[blks_cnt];

    preprocess(a, n, block);
    
    cout << "query(3,8) : " << query(a, block, 3, 8) << endl; 
	cout << "query(1,6) : " << query(a, block, 1, 6) << endl; 
	cout << "query(8,8) : " << query(a, block, 8, 8) << endl; 
    update(a, block, 8, 0); 
	cout << "query(8,8) : " << query(a, block, 8, 8) << endl; 
	return 0; 
}
