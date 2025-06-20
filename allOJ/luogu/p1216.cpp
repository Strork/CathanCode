#include <bits/stdc++.h>
using namespace std;
int n;
int a[1005][1005];
int dp[1005][1005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> a[i][j];
        }
    }
    dp[1][1] = a[1][1];
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j];
        }
    }
    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}