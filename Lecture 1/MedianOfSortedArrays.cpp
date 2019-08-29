/*
    Question: 
    There are two sorted arrays A and B of size m and n respectively.
    Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).
    Eg.
    A = {2, 4, 5}
    B = {1, 3}
    output = 3
    Time complexity expected = O(log(m+n))
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
    
    if(A.size()>B.size())return findMedianSortedArrays(B,A);
    
    int x = A.size();
    int y = B.size();
    
    int low =0;
    int high = x;
    
    while(low<=high)
    {
        int partX = (low+high)/2;
        int partY = (x+y+1)/2-partX;
        
        int maxleftX = (partX==0)?INT_MIN:A[partX-1];
        int minrightX = (partX==x)?INT_MAX:A[partX];
        
        int maxleftY = (partY==0)?INT_MIN:B[partY-1];
        int minrightY = (partY==y)?INT_MAX:B[partY];
        
        if(maxleftX<=minrightY && maxleftY<=minrightX)
        {
            if((x+y)%2==0)
                return  (double)(max(maxleftX,maxleftY)+min(minrightX,minrightY))/2;
            else
                return (double)(max(maxleftX,maxleftY));
        }
        else if(maxleftX>minrightY)
        {
            high = partX-1;
        }
        else if(maxleftY>minrightX)
        {
            low = partX+1;
        }
    }
}

int main() {
    vector<int> A{2, 4, 5};
    vector<int> B{1, 3};
    cout << "The median of the resultant array would be " << findMedianSortedArrays(A, B);
}