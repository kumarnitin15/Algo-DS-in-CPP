/*
    Question: 
    Given a N cross M matrix in which each row is sorted, find the overall median of the matrix. 
    Assume N*M is odd.
    Eg.
    Matrix = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}}
    output = 5
    Note: No extra memory is alowed
*/

/* 
    Important points: 
    The following solution is not 100% correct. 
    Try to find the mistakes and the ways to rectify the problems.
    It is a classic example of the case where you need to ask more questions from the interviewer.
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int matrix_median(vector<vector<int>> v){
    int min=INT_MAX, max=INT_MIN;
    int rows=v.size(), cols=v[0].size();
    for(int i=0;i<rows;i++)
    {
        if(min>v[i][0])
            min=v[i][0];
        
        if(max<v[i][cols-1])
            max=v[i][cols-1];
    }
    
    int desired=(rows*cols+1)/2;
    int place=0;
    int s = min, e = max;
    while(s<e)
    {
       int mid=(s+e)/2;
        place=0;
        for(int i=0;i<rows;i++)
            place += upper_bound(v[i].begin(),v[i].end(),mid)-v[i].begin();
        
        if(place<desired)
            s=mid+1;
        else
            e=mid;
    }
    return s;
}

int main() {
    vector<vector<int>> v{{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout << matrix_median(v);
}