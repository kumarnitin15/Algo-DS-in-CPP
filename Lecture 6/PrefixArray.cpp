#include <iostream> 
using namespace std; 

int getSum(int prefix[], int l, int r) 
{ 
    int sum;
    if(l > 0)
	    sum = prefix[r]-prefix[l-1]; 
    else
        sum = prefix[r];
    return sum;
}  

int main() 
{ 
	int arr[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

    int prefix[n]; 
    prefix[0] = arr[0];
   
    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }

	int l = 2, r = 5;
    cout << "The sum for query [" << l << "..." << r << "] : " << getSum(prefix, l, r) << endl;

	return 0; 
}