#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll f[205][205], a[205];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int len = 3; len <= n + 1; ++len) {
        for (int i = 1; i <= 2 * n + 1; ++i) {
            int j = i + len - 1;
            if (j > 2 * n + 1) break;
            for (int k = i + 1; k <= j - 1; ++k) {
                f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[k] * a[j]);
            }
            //printf("%lld %lld %lld\n", i, j, f[i][j]);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, f[i][i + n]);
    }
    cout << ans << endl;
    return 0;
}