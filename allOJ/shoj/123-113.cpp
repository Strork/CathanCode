#include <bits/stdc++.h>
using namespace std;
int x, y;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    cin >> x >> y;
    cout << gcd(x, y) << endl;
    return 0;
}