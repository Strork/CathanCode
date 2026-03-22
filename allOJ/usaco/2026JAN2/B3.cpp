#include <bits/stdc++.h>
using namespace std;
int n, q;
typedef long long ll;
ll a[100005];

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i) a[i] = min(a[i], a[i - 1] << 1);
    }
    if (n <= 32)
        for (int i = n; i <= 35; ++i) a[i] = a[i - 1] << 1;  // 如果不够
    for (int i = 1; i <= q; ++i) {
        ll x;
        cin >> x;
        ll sum = 0, ans = 0;
        for (int i = 0; i < 32; ++i)
            if ((1LL << i) & x) sum += a[i];
        for (int i = 31; i >= 0; --i) {
            ll t = 1LL << i;
            if (t & x) {
                if (sum >= a[i + 1]) {
                    ans += a[i + 1];
                    break;
                } else {
                    sum -= a[i];
                    ans += a[i];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}