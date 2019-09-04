/* 

1. 

for(int i=0; i<3; i++)
    // O(1) ops

T = O(1)

2.

for(int i=0; i<n; i++)
    // O(1) ops

T = O(n)

3.

for (int i=1; i<=m; i++) {
    for (int j=1; j<=n; j++)
          // O(1) ops
}

T = O(m*n)

4. 

for(int i=0; i<m; i++)
    // O(1) ops

for(int j=0; j<n; j++)
    // O(1) ops

T = O(m+n)

5.

for (int i=n; i>0; i/=c) {
    // O(1) ops
}

T = O(logn)

6.

for(int i=n; i>1; i=sqrt(i)) { 
    // O(1) ops
}

T = O(loglogn)

*/