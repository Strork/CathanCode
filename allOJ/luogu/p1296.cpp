#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, d;
int a[1000005];

int main() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int t = max(a[i] - d, 0);
        int id = lower_bound(a + 1, a + i, t) - a;
        ans += i - id;
    }
    cout << ans << endl;
    return 0;
}