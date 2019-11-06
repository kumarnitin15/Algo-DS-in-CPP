#include <iostream>
using namespace std;

#define ll long long 

ll fastModExp(ll a, ll b, ll mod){
    ll res = 1;
    while(b>0){
        if(b&1){
            res = ((res) * (a%mod)) % mod;
        }
        a = ((a%mod)*(a%mod))%mod;
        b = b>>1;
    }
    return res;
}

int main() {
    int a = 3, b = 4, mod = 10;
    cout << fastModExp(a, b, mod);
}
