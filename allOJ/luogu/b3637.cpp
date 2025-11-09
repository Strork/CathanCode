#include<bits/stdc++.h>
using namespace std;
int dp[5005]; // 长度
int f[5005];
int a[5005];
int ans = 0;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1); // 上升长度
        }
    }
    for (int i = n; i >= 1; --i) {
        f[i] = 1;
        for (int j = n; j > i; --j) {
            if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1); // 下降长度
        }
        ans = max(ans, dp[i] + f[i] - 1);
    }
    cout << n - ans << endl;
    return 0;
}