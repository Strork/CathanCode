#include <bits/stdc++.h>
using namespace std;
int f[1005];              // 付出上限
int cost[105], got[105];  // f[i] = max(f[i - cost[i]] + get[i], f[i]);
int dp[10005];            // 收获上限
int n, T;

void dp1() {
    for (int i = 1; i <= n; ++i)
        for (int j = T; j >= cost[i]; j--)
            f[j] = max(f[j - cost[i]] + got[i], f[j]);
    for (int i = 1; i <= T; ++i) cout << f[i] << endl;
}

void dp2() {
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 10000; j >= got[i]; j--)
            dp[j] = min(dp[j - got[i]] + cost[i], dp[j]);
    for (int i = 1; i <= 105; ++i) cout << dp[i] << endl;
}

int main() {
    cin >> T >> n;
    for (int i = 1; i <= n; ++i) cin >> cost[i] >> got[i];
    dp2();
    return 0;
}