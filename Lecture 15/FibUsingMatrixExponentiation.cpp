#include<bits/stdc++.h> 
using namespace std; 

void multiply(int a[3][3], int b[3][3]) 
{ 
	int mul[3][3]; 
	for (int i = 0; i < 3; i++) 
	{ 
		for (int j = 0; j < 3; j++) 
		{ 
			mul[i][j] = 0; 
			for (int k = 0; k < 3; k++) 
				mul[i][j] += a[i][k]*b[k][j]; 
		} 
	} 

	// storing the multiplication result in a[][] 
	for (int i=0; i<3; i++) 
		for (int j=0; j<3; j++) 
			a[i][j] = mul[i][j]; // Updating our matrix 
} 

// Function to compute F raise to power n-2. 
int power(int F[3][3], int n) 
{ 
	int M[3][3] = {{1,1,0}, {1,0,0}, {0,1,0}}; 

	// Multiply it with initial values i.e with 
	// F(0) = 0, F(1) = 1, F(2) = 1 
	if (n==1) 
		return F[0][0] + F[0][1]; 

	power(F, n/2); 

	multiply(F, F); 

	if (n%2 != 0) 
		multiply(F, M); 

	// Multiply it with initial values i.e with 
	// F(0) = 0, F(1) = 1, F(2) = 1 
	return F[0][0] + F[0][1] ; 
} 

int findNthTerm(int n) 
{ 

	int F[3][3] = {{1,1,0}, {1,0,0}, {0,1,0}} ; 

	//Base cases 
	if(n==0) 
		return 0; 
	if(n==1 || n==2) 
		return 1; 

	return power(F, n-2); 
} 

int main() 
{ 
    int n = 7; 
    cout << "F(7) is " << findNthTerm(n); 
    return 0; 
} 
