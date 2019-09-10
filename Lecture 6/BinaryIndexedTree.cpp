#include <iostream> 
using namespace std; 

int getSum(int BITree[], int index) 
{ 
	int sum = 0;
    index = index + 1; 

	while (index>0) 
	{ 
		sum += BITree[index]; 
		index -= index & (-index); 
	} 
	return sum; 
} 

void updateBIT(int BITree[], int n, int index, int val) 
{ 
	index = index + 1; 

	while (index <= n) 
	{ 
	    BITree[index] += val; 
	    index += index & (-index); 
	} 
} 

int main() 
{ 
	int arr[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

    int BITree[n+1]; 
	for (int i=1; i<=n; i++) 
		BITree[i] = 0; 
	for (int i=0; i<n; i++) 
		updateBIT(BITree, n, i, arr[i]); 

	cout << "Sum of elements in arr[0..5] is " << getSum(BITree, 5); 

	arr[3] += 6; 
	updateBIT(BITree, n, 3, 6);

	cout << "\nSum of elements in arr[0..5] after update is " << getSum(BITree, 5); 
	return 0; 
}