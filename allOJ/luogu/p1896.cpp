#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[10][1<<10][85]; // 前 i 行，状态为 j，放了 k 个国王
int c[1<<10]; // 统计二进制中 1 的个数
int n, m;
ll ans;

void pre() {
    for (int i = 0; i < (1 << n); ++i) {
        int t = i;
        while (t) {
            ++c[i];
            t &= (t - 1);
        }
    } // 统计每个图案中 1 的个数
    for (int i = 0; i < (1 << n); ++i) {
        if (i & (i << 1)) continue;
        f[1][i][c[i]] = 1; // 一种合法方案
    }  // f[1][10101][3] = 1;
}

int main() {
    cin >> n >> m;
    pre();
    for (int i = 2; i <= n; ++i) { // 第 i 行
        for (int j = 0; j < (1 << n); ++j) { // 这行状态为 j
            if (j & (j << 1)) continue; // 先排除左右相邻攻击的
            for (int k = 0; k < (1 << n); ++k) { // 枚举一下另外一个状态 k
                if (j & k) continue; // 排除相互攻击
                if (j & (k << 1)) continue;
                if ((j << 1) & k) continue;
                for (int d = m; d >= c[j]; --d) 
                    f[i][j][d] += f[i - 1][k][d - c[j]];
            }
        }
    }
    for (int i = 0; i < (1 << n); ++i) ans += f[n][i][m];
    cout << ans << endl;
    return 0;
}