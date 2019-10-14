#include <iostream>
#include <stack>
using namespace std;

void printStockSpan(int a[], int n){
    stack<int> st; int span[n];
    span[0] = 1;
    st.push(0);
    for(int i=1; i<n; i++){
        cout << span[i-1] << " ";
        span[i] = 1;
        while(!st.empty() && a[st.top()] < a[i]){
            span[i] += span[st.top()];
            st.pop();
        }
        st.push(i);
    }
    cout << span[n-1];
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    printStockSpan(a, n);
}