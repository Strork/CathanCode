#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll a[15];
ll ans = 1;

ll gcd(ll x, ll y) {
    if (x < y) swap(x, y);
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ans = ans * a[i] / gcd(ans, a[i]);
    }
    cout << ans << endl;
    return 0;
}