#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int n, k;
ll nd[N], hv[N];

bool check(ll x) {  // 目标是 x 台
    ll need = 0;
    for (int i = 1; i <= n; ++i) {
        ll target = nd[i] * x;
        if (target <= hv[i]) continue;
        need += target - hv[i];
        if (need > k) return false;
    }
    return true;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) scanf("%lld", &nd[i]);
    for (int i = 1; i <= n; ++i) scanf("%lld", &hv[i]);
    ll l = 0, r = 1LL << 31;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    cout << ans << endl;
    return 0;
}