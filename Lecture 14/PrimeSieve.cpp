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

    for(int i=3; i<=n; i+=2){
        if(p[i]){
            for(int j=i*i; j<=n; j+=i)
                p[j] = 0;
        }
    }

    vector<int> primes;
    for(int i=0; i<=n; i++){
        if(p[i])
            primes.push_back(i);
    }
    return primes;
}

int main() {
    int n = 25;
    vector<int> primes = primeSieve(n);
    for(int prime : primes)
        cout << prime << " ";
    cout << endl;
}
