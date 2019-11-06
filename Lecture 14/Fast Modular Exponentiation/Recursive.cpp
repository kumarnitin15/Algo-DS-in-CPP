#include <iostream>
using namespace std;

#define ll long long

ll fastModExp(ll a, ll b, ll mod){
    if (a == 0) 
        return 0; 
    if (b == 0) 
        return 1; 
    ll y; 
    if (b % 2 == 0) { 
        y = fastModExp(a, b/2, mod); 
        y = (y*y)% mod; 
    }  
    else { 
        y = a%mod; 
        y = (y * fastModExp(a, b-1, mod) % mod) % mod; 
    } 
    return y;
}

int main() {
    int a = 3, b = 4, mod = 10;
    cout << fastModExp(a, b, mod);
}
