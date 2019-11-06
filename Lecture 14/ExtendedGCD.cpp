#include <iostream>
using namespace std;

void extendedGCD(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return;
    }
    extendedGCD(b, a%b, x, y);
    int x1 = x, y1 = y;
    x = y1;
    y = x1 - (a/b)*y1;
}

int main() {
    int a = 30, b = 18;
    int x, y;
    extendedGCD(a, b, x, y);
    cout << x << " " << y;
}
