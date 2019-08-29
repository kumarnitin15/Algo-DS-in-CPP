/*
    Question: 
    Find the number of elements smaller than or equal to a given number in a sorted array.
    Eg. 
    Given array = {1, 23, 55, 78, 95, 103},  x = 80
    ans = 4.
 */

#include <iostream>
#include <vector>
using namespace std; 

int numOfElemSmaller(vector<int> v, int x){
    int n = v.size();
    int s = 0, e = n-1, pos=-1;
    while(s <= e){
        int m = (s+e)/2;
        if(v[m] <= x){
            pos = m;
            s = m+1;
        }
        else
            e = m-1;
    }

    // pos is the index, so pos+1 will be the number of elements
    return pos+1;
}
  
int main() 
{ 
    vector<int> v{1, 23, 55, 78, 95, 103};
    int x = 80;
    cout << numOfElemSmaller(v, x) << " elements are smaller than or equal to " << x;
    return 0; 
} 