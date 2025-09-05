#include <bits/stdc++.h>
using namespace std;
int n;
long long x;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        x ^= t; // 把所有数异或, 即a[1]^a[2]^...^a[n]
    }
    cout << x << ' ' << 0 << endl;
    return 0;
}
