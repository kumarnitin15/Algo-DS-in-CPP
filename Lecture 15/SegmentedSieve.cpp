#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int N = 1000000;
int p[N+1] = {0};

void sieve(int n){
    
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
}

vector<int> segmentedSieve(long long int a, long long int b){
    sieve(sqrt(b));
    vector<int> ps(b-a+1, 1);
    for(long long int i=2; i*i <= b; i++){
        if(p[i]){
            for(long long int j=a; j<=b; j++){
                if(j == i)
                    continue;
                if(j%i == 0)
                    ps[j-a] = 0;
            }
        }
    }
    vector<int> primes;
    for(long long int j=a; j<=b; j++){
        if(ps[j-a])
            primes.push_back(j);
    }
    return primes;
}

int main() {
    int a = 25, b = 48;
    vector<int> primes = segmentedSieve(a, b);
    for(long long int prime : primes)
        cout << prime << " ";
}
