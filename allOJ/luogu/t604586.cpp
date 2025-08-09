#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int dp[1005][1005];
int a[1005];

void dfs(int x, int y, int opt) {
    if (dp[x][y]) return;
    if (x == y) {
        dp[x][y] = a[x];
        return;
    }
    if (!opt) dp[x][y] = 0;
    else dp[x][y] = 1e9+7;
    for (int i = x; i < y; ++i) {
        dfs(x, i, opt^1); // 左区间
        dfs(i + 1, y, opt^1); // 右区间
        if (opt == 0) { // 如果是雪来分割
            dp[x][y] = max(dp[x][y], min(dp[x][i], dp[i+1][y]));
        } else {
            dp[x][y] = min(dp[x][y], max(dp[x][i], dp[i+1][y]));
        }
    }
}

void baoli() {
    if (n == 1) cout << a[1] << endl;
    else if (n == 2) cout << min(a[1], a[2]) << endl;
    else {
        dfs(1, n, 0);
        cout << dp[1][n] << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        memset(dp, 0, sizeof(dp));
        if (n <= 1000) baoli();
    }
    return 0;
}