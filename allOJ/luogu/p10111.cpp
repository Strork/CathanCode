#include <bits/stdc++.h>
using namespace std;
int f[1005][1005][3];  // 轮数、换牌次数、出牌
int n;
int b[1005], a[1005], c[1005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        cin >> b[i];
        b[i] += b[i - 1];  // 直接求前缀和就好
    }
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i <= n; ++i) {         // 第 i 轮
        for (int j = 0; j < i; ++j) {      // 换了 j 次牌
            for (int k = 0; k < 3; ++k) {  // 本次出牌为 k
                int core = 0;
                if (k == c[i])
                    core = a[i];  // 平局得分
                else if ((c[i] + 1) % 3 == k)
                    core = a[i] << 1;                // 赢局得分
                f[i][j][k] = f[i - 1][j][k] + core;  // 不换牌
                if (j == 0) continue;
                f[i][j][k] = max(f[i - 1][j - 1][(k + 1) % 3] + core,
                                 f[i][j][k]);  // 换牌
                f[i][j][k] = max(f[i - 1][j - 1][(k + 2) % 3] + core,
                                 f[i][j][k]);  // 换牌
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, f[n][i][0] - b[i]);
        ans = max(ans, f[n][i][1] - b[i]);
        ans = max(ans, f[n][i][2] - b[i]);
    }
    cout << ans << endl;
    return 0;
}