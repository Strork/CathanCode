#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[2005][2005];
int n, a[2005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int len = n - 1; len >= 1; --len) { // 区间长度
        for (int i = 1; i < n; ++i) { // 左端点
            int j = i + len - 1; // 右端点
            if (j > n) break;
            if (i-1 >= 1) f[i][j] = max(f[i-1][j] + a[i-1] * (n-len), f[i][j]); // 卖i-1
            if (j+1 <= n) f[i][j] = max(f[i][j], f[i][j+1] + a[j+1] * (n-len)); // 卖j+1
            // printf("%d %d %d\n", i, j, f[i][j]);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, f[i][i] + a[i] * n);
    }
    cout << ans << endl;
    return 0;
}