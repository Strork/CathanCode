#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    // freopen("a.in", "r", stdin);
    int q; cin >> q; while (q--) {
        ll n;
        cin >> n;
        long double t = sqrtl(n);
        ll x = t;
        ll ans = 3LL * (x - 1) + 1LL;
        ll x2 = x * x;
        ans += (n - x2) / x;
        cout << ans << endl;
    }
    return 0;
}