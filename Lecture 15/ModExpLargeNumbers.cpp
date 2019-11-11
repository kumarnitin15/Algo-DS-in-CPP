#include <iostream>
#include <cstring>
using namespace std;
#define ll long long

ll p = 1000000007;

ll stringToInt(string num, ll m){
    ll ans = 0;
    for(int i=0; i<num.length(); i++){
        ans = ((ans*10)%m +(num[i]-'0'))%m;
    }
    return ans;
}

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
    string a  = "29342758742901275975837949024238738932";
    string b = "478397293810979427858342401320799349";

    ll x = stringToInt(a, p);
    ll y = stringToInt(b, p-1);

    cout << fastModExp(x, y, p) << endl;
}