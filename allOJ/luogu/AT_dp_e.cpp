#include <bits/stdc++.h>
using namespace std;
int n, s[1500], f[1500], dp[991000], k = 4e5, ans;
int main() {
    cin >> n;
    memset(dp, -0x3f, sizeof(k));
    dp[k] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> f[i];
    }
    for (int i = 1; i <= n; i++) {
        if (f[i] > 0) {
            for (int j = 2 * k; j >= f[i]; j--) {
                dp[j] = max(dp[j], dp[j - f[i]] + s[i]);
            }
        } else {
            for (int j = 0; j <= 2 * k + f[i]; j++) {
                dp[j] = max(dp[j], dp[j - f[i]] + s[i]);
            }
        }
    }
    for (int i = k; i <= 2 * k; i++) {
        if (dp[i] > 0) {
            ans = max(ans, dp[i] + i - k);
        }
    }
    cout << ans;
    return 0;
}
