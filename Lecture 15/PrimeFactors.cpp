#include <iostream>
#include <vector>
using namespace std;

const int N = 1000000;
int p[N+1] = {0};

vector<int> primeSieve(int n){
    
    p[0] = p[1] = 0;
    p[2] = 1;
    
    for(int i=3; i<=n; i+=2)
        p[i] = 1;
        
    for(long long int i=3; i<=n; i+=2){
        if(p[i]){
            for(long long int j=i*i; j<=n; j+=i)
                p[j] = 0;
        }
    }
    vector<int> primes;
    for(int i=2; i<=n; i++){
        if(p[i])
            primes.push_back(i);
    }
    return primes;
}

vector<int> factorize(int n, vector<int> primes){
    int i=0;
    vector<int> factors;
    int p = primes[i];
    while(p*p <= n){
        if(n%p == 0){
            factors.push_back(p);
            while(n%p == 0)
                n = n/p;
        }
        i++;
        p = primes[i];
    }
    if(n > 1)
        factors.push_back(n);
    return factors;
}

int main() {
   int n = 210;
   vector<int> factors = factorize(n, primeSieve(n));
   for(int factor : factors)
       cout << factor << " ";
}
