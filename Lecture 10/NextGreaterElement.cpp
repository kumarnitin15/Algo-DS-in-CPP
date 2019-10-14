// Question: Find the next greater element in a circular array

#include <iostream>
#include <stack>
using namespace std;

void printNextGreater(int a[], int n){
    int arr[2*n];
    for(int i=0; i<2*n; i++){
        arr[i] = a[i%n];
    }
    int greater[n] = {0};
    stack<int>st;
    for(int i=0; i<2*n; i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            int ele = st.top();
            if(ele < n)
                greater[ele] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    while(!st.empty()){
        int ele = st.top();
        if(ele < n) 
            greater[ele] = -1;
        st.pop();
    }

    for(int i=0; i<n; i++)
        cout << greater[i] << " ";
}

int main(){
    int a[10] = {6,4,8,22,43,12,78,47,88,50};
    printNextGreater(a, 10);
}