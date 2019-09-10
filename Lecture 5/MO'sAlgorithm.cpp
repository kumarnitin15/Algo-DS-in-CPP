#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Query {
    int L, R;
};

int block;

bool compare(Query q1, Query q2){
    if(q1.L/block != q2.L/block)
        return q1.L/block < q2.L/block;
    return q1.R <= q2.R;
}

void sumQueries(int a[], int n, Query q[], int m){
    block = (int)sqrt(n);
    
    sort(q, q+m, compare);

    int currL = 0, currR = 0, sum = 0;
    
    for(int i=0; i<m; i++){
        int L = q[i].L, R = q[i].R;
        while(currL < L){
            sum -= a[currL];
            currL++;
        }
        while(currL > L){
            sum += a[currL-1];
            currL--;
        }
        while(currR > R+1){
            sum -= a[currR-1];
            currR--;
        }
        while(currR <= R){
            sum += a[currR];
            currR++;
        }
        cout << sum << endl;
    }
}

int main() {
    int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8}; 
    int n = sizeof(a)/sizeof(a[0]); 
    Query q[] = {{0, 4}, {1, 8}, {3, 6}}; 
    int m = sizeof(q)/sizeof(q[0]); 
    sumQueries(a, n, q, m); 
}
