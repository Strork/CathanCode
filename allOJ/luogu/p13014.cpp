#include <bits/stdc++.h>
using namespace std;
int a[100004];
int n, q;

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    int gcd1 = 0;
    for (int i = 2; i <= n; ++i) gcd1 = __gcd(gcd1, a[i] - a[1]);
    for (int i = 1; i <= q; ++i) cout << __gcd(gcd1, a[1] + i) << endl;
    return 0;
}