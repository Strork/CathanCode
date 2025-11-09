#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll x[1005], y[1005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
    ll ans = 1LL << 50;
    for (int o = 1; o < n; ++o) {
        ll r = 0;
        for (int i = o + 1; i <= n; ++i) {
            ll tx = (x[o] - x[i]) * (x[o] - x[i]);
            ll ty = (y[o] - y[i]) * (y[o] - y[i]);
            r = max(r, tx + ty);
        }
        ans = min(ans, r);
    }
    printf("%.4lf\n", 3.1415926 * (1.0 * ans));
    return 0;
}